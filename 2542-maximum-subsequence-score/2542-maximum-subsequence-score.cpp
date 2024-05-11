class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0; 
        vector<pair<int,int>> vec; 
        for(int i = 0; i < nums2.size(); i++){
            vec.push_back({nums2[i],i}); 
        }

        sort(vec.rbegin(), vec.rend()); 
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        long long sum = 0; 
        for(int i = 0; i < vec.size(); i++){
            pair<int,int> p = vec[i]; 
            sum += nums1[p.second]; 
            pq.push(nums1[p.second]); 
            if(pq.size() == k){
                res = max(res, sum * p.first); 
            }

            if(pq.size() > k - 1){
                sum -= pq.top(); 
                pq.pop(); 
            }
        }

        return res; 
    }
};