struct DLLNode{  // Changed name
    int key, val; 
    DLLNode* next; 
    DLLNode* prev; 
    DLLNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    unordered_map<int, DLLNode*> hashMap;  // Use DLLNode
    int cap; 
    DLLNode* header;  // Use DLLNode
    DLLNode* tail;    // Use DLLNode
    
    LRUCache(int capacity) {
        cap = capacity; 
        header = new DLLNode(-1,-1); 
        tail = new DLLNode(-1,-1); 
        header->next = tail;
        tail->prev = header;  
    }

    void addToFront(DLLNode* node){
        node->next = header->next; 
        node->prev = header; 
        header->next->prev = node; 
        header->next = node; 
    }

    void removeNode(DLLNode* node){
        node->prev->next = node->next; 
        node->next->prev = node->prev; 
    }

    void moveToFront(DLLNode* node){
        removeNode(node); 
        addToFront(node); 
    }
    
    int get(int key) {
        if(!hashMap.count(key)) return -1; 
        DLLNode* node = hashMap[key]; 
        moveToFront(node); 
        return node->val; 
    }
    
    void put(int key, int value) {
        if(hashMap.count(key)){
            DLLNode* node = hashMap[key]; 
            node->val = value; 
            moveToFront(node); 
        } else{
            DLLNode* newNode = new DLLNode(key,value); 
            hashMap[key] = newNode; 
            addToFront(newNode); 

            if(hashMap.size() > cap){
                DLLNode* lru = tail->prev; 
                removeNode(lru); 
                hashMap.erase(lru->key); 
                delete lru; 
            }
        }
    }
};