class MyHashSet {
private: 
    struct LinkedList{
        int key; 
        LinkedList* next; 
        LinkedList(int key, LinkedList* next){
            this->key = key; 
            this->next = next; 
        }
    };
public:
    int size = 10000; 
    LinkedList* buckets[10000]; 
    int hashKey(int key, int size){
        return key % size; 
    }
    MyHashSet() {
        for(int i = 0; i < size; i++){
            buckets[i] = new LinkedList(-1,nullptr); 
        }
    }
    
    void add(int key) {
        int index = hashKey(key, size); 
        LinkedList* curr = buckets[index]; 
        while(curr->next != nullptr){
            if(curr->next->key == key){
                return; 
            }
            curr = curr->next; 
        }
        curr->next = new LinkedList(key,nullptr); 
    }
    
    void remove(int key) {
        int index = hashKey(key,size); 
        LinkedList* curr = buckets[index]; 
        while(curr->next != nullptr){
            if(curr->next->key == key){
                LinkedList* tobeDeleted = curr->next;
                curr->next = curr->next->next;
                delete tobeDeleted;
                return; 
            }
            curr = curr->next; 
        }
    }
    
    bool contains(int key) {
        int index = hashKey(key,size); 
        LinkedList* curr = buckets[index]; 
        while(curr->next != nullptr){
            if(curr->next->key == key){
                return true; 
            }
            curr = curr->next; 
        }
        return false; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */