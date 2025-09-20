class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer; 
        map<int,int> hashMap; 
        for(int n : nums1) hashMap[n] = 1; 
        for(int n : nums2) {
            if(hashMap[n] > 0 && hashMap.count(n)){
                answer.push_back(n); 
                hashMap[n]--; 
            }
        }
        return answer; 
    }
};