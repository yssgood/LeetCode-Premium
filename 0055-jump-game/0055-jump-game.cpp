class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(i > maxJump) return false; 
            maxJump = max(maxJump, nums[i] + i); 
            if(maxJump >= nums.size()-1) return true; 
        }
        return true; 
    }
};