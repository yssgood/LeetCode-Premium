class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> answer(nums.size(), 0); 
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>> pq; 
        map<long long, long long> hashMap; 
        hashMap[nums[0]] += freq[0]; 
        pq.push({freq[0], nums[0]}); 
        answer[0] = freq[0]; 
        
        for(int i = 1; i < nums.size(); i++){
            
            hashMap[nums[i]] += freq[i]; 
            
            pair<long, long> p = pq.top(); 
            
            if(hashMap[p.second] != p.first){
                pq.pop();
                pq.push({hashMap[p.second], p.second}); 
            } else{
                pq.push({hashMap[nums[i]], nums[i]});
            }
            
            // if(hashMap[pq.top().second] != pq.top().first){
            //     //answer[i] = hashMap[pq.top().second]; 
            //     long long number = pq.top().second; 
            //     pq.pop();
            //     pq.push({hashMap[number], number}); 
            // } 

            while(hashMap[pq.top().second] != pq.top().first){
                long long number = pq.top().second; 
                pq.pop(); 
                pq.push({hashMap[number], number});
            }

            answer[i] = pq.top().first; 
            
        }
        
        return answer; 
    }
};