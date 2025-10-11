class RandomizedSet {
public:
    map<int,int> hashMap; 
    vector<int> container; 
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

        int index = hashMap[val]; 
        int last = container.back(); 

        container[index] = last; 
        container[container.size()-1] = val; 
        container.pop_back(); 

        hashMap.erase(val);
        hashMap[last] = index; 

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