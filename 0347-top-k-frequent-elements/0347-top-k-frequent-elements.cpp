class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap; 
        for(int n : nums){
            hashMap[n]++; 
        }
        vector<int> answer; 
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq; 
        for(auto& it : hashMap){
            pq.push({it.second, it.first}); 
        }
        while(k--){
            answer.push_back(pq.top().second);
            pq.pop(); 
        }
        return answer; 
    }
};