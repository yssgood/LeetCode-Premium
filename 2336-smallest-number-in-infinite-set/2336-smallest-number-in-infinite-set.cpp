class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>, greater<int>> minq; 
    set<int> available; 
    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++){
            minq.push(i); 
        }
    }
    
    int popSmallest() {
        int res = minq.top();
        available.insert(res);
        minq.pop(); 
        return res; 
    }
    
    void addBack(int num) {
        if(available.contains(num)){
            available.erase(num); 
            minq.push(num); 
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */