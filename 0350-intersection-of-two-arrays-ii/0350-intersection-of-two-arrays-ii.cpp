class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer; 
        map<int,int> hashMap; 
        for(int i = 0; i < nums1.size(); i++) hashMap[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++){
            if(hashMap.count(nums2[i]) && hashMap[nums2[i]] > 0){
                answer.push_back(nums2[i]); 
                hashMap[nums2[i]]--; 
            }
        }

        return answer; 
    }
};