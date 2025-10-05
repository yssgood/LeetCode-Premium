class RandomizedSet {
public:
    vector<int> container; 
    map<int,int> hashMap; 
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hashMap.count(val)) return false; 
        container.push_back(val); 
        hashMap[val] = container.size()-1; 

        return true; 
    }
    
    bool remove(int val) {
        if(!hashMap.count(val)) return false; 
        int targetIndex = hashMap[val]; 
        //swap(container[targetIndex], container[container.size()-1]); 
        int lastNumber = container.back(); 
        container[targetIndex] = lastNumber; 
        container.pop_back(); 
        //hashMap[container[targetIndex]] = targetIndex; 
        hashMap[lastNumber] = targetIndex; 
        hashMap.erase(val); 
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