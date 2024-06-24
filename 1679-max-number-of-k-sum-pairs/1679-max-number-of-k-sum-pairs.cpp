class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> hashMap; 
        int answer =0; 
        for(int i = 0; i < nums.size(); i++){
            if(hashMap[k - nums[i]] > 0){
                answer++;
                hashMap[k- nums[i]]--; 
                continue; 
            }
            hashMap[nums[i]]++; 
        }
        return answer; 
    }
};