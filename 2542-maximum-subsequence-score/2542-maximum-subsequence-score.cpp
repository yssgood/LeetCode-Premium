class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        int n=nums2.size();
        // to track indexs after sorting
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],i});
        }
        sort(v.rbegin(),v.rend());
        long long sum=0;
        long long maxi=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<v.size();i++){
            auto &[a,b]=v[i];
            sum+=nums1[b];
            pq.push(nums1[b]);
            //update maxi if the heap size is k
            if(pq.size()==k)maxi=max(maxi,sum*a);       
            //maintaining the k-1 maximum element
            if(pq.size()>k-1){
                sum-=pq.top();
                pq.pop();
            }
        }
        return maxi;
    }
};