class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i],i}); 
        }

        for(int i = 0; i < k; i++){
            pair<int,int> curr = pq.top(); 
            pq.pop(); 

            int num = curr.first, index = curr.second;  
            nums[index] *= multiplier; 
            pq.push({num * multiplier, index}); 
        }

        return nums; 
    }
};