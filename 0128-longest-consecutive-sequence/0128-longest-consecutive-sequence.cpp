class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> hashMap; 
        int longest = 0; 
        for(int n : nums) hashMap[n]++;
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i]; 
            if(!hashMap.count(curr-1)){
                int streak = 0; 
                while(hashMap.count(curr) && hashMap[curr] > 0){
                    hashMap[curr]--; 
                    streak++; 
                    curr = curr + 1; 
                }
                longest = max(longest, streak); 
            }
        }
        return longest; 
    }
};