class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIndex = nums.size()-1; 
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i] + i >= lastIndex){
                lastIndex = i; 
            }
        }
        return lastIndex == 0;
    }
};