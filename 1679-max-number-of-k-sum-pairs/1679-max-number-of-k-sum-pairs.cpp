class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> hashMap; 
        int answer = 0; 
        for(int i = 0; i < nums.size(); i++){
            int target = k - nums[i]; 
            if(hashMap.count(target)){
                answer++; 
                hashMap[target]--; 
                if(hashMap[target] == 0) hashMap.erase(target); 
                continue; 
            }
            hashMap[nums[i]]++; 
        }

        return answer; 
    }
};