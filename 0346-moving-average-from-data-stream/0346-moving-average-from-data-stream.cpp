class MovingAverage {
public:
    queue<int> q; 
    int limit = 0;
    int lastSum = 0;  
    MovingAverage(int size) {
        limit = size; 
    }
    
    double next(int val) {
        if(!q.empty() && q.size() == limit){
            lastSum -= q.front();
            q.pop(); 
        }
        lastSum += val; 
        q.push(val); 
        return (double) lastSum / q.size(); 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */