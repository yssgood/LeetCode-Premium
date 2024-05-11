class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n = nums2.size(); 

        for(int i = 0; i < n; i++){
            v.push_back({nums2[i],i}); 
        }

        sort(v.rbegin(), v.rend()); 
         
        long long sum = 0; 
        long long answer = 0; 

        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int i = 0; i < v.size(); i++){
            pair<int,int> p = v[i]; 
            sum += nums1[p.second]; 
            pq.push(nums1[p.second]); 
            if(pq.size() == k){
                answer = max(answer, sum * p.first); 
                sum -= pq.top(); 
                pq.pop(); 
            }
            // if(pq.size()  > k -1){
            //     sum -= pq.top();
            //     pq.pop(); 
            // }
        }

        return answer; 
    }
};