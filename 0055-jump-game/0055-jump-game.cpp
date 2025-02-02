class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true; 
        int jump = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            if(jump < i) break; 
            jump = max(jump, i + nums[i]); 
            if(jump >= nums.size()-1) return true; 
        }
        return false; 
    }
};