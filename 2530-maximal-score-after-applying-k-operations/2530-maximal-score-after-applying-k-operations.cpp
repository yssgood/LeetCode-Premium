class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq; 
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]); 
        }
        long long score = 0; 
        while(k--){
            long double top = pq.top(); 
            pq.pop(); 
            score += top; 
            //cout << ceil(top / 3) << endl; 
            pq.push(ceil(top / 3)); 

        }

        return score; 
    }
};