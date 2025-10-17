struct Node{
    int key, val; 
    Node* next; 
    Node* prev; 
    Node(int key, int val){
        this->key = key; 
        this->val = val; 
        this->next = nullptr; 
        this->prev = nullptr; 
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> hashMap; 
    int cap = 0; 
    Node* header;
    Node* tail; 
    LRUCache(int capacity) {
        cap = capacity; 
        header = new Node(-1,-1); 
        tail = new Node(-1,-1); 
        header->next = tail;
        tail->prev = header; 
    }
    
    int get(int key) {
        if(!hashMap.count(key)) return -1; 

        Node* target = hashMap[key]; 
        target->prev->next = target->next; 
        target->next->prev = target->prev; 

        target->prev = header; 
        target->next = header->next; 
        header->next->prev = target; 
        header->next = target;  

        return target->val; 
    }
    
    void put(int key, int value) {
        if(hashMap.count(key)){
            Node* target = hashMap[key];
            target->val = value; 

            target->prev->next = target->next; 
            target->next->prev = target->prev; 

            target->prev = header; 
            target->next = header->next;  
            header->next->prev = target; 
            header->next = target; 
        } else{
            Node* newNode = new Node(key,value); 
            hashMap[key] = newNode; 

            newNode->prev = header; 
            newNode->next = header->next; 
            header->next->prev = newNode; 
            header->next = newNode; 

            if(hashMap.size() > cap){
                Node* lru = tail->prev; 
                lru->prev->next = lru->next; 
                lru->next->prev = lru->prev; 

                hashMap.erase(lru->key); 
                delete lru; 
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */