class RandomizedSet {
public:
    vector<int> container; 
    map<int,int> hashMap; 
    int global_counter = 0; 
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hashMap.count(val)) return false;  
        container.push_back(val); 
        hashMap[val] = global_counter++; 
        return true; 
    }
    
    bool remove(int val) {
        if(!hashMap.count(val)) return false; 
        int removingIndex = hashMap[val]; 
        int lastNumber = container.back(); 
        container[removingIndex] = lastNumber; 
        container.pop_back(); 
        hashMap[lastNumber] = removingIndex; 
        hashMap.erase(val); 
        global_counter--; 
        return true; 
    }
    
    int getRandom() {
        return container[rand() % container.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */