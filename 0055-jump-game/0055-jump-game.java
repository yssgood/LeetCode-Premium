class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length == 1) return true; 
        int maxJump = nums[0];  
        for(int i = 0; i <= maxJump; i++){
            maxJump = Math.max(maxJump, i + nums[i]); 
            if(maxJump >= nums.length-1) return true; 
        }
        return false; 
    }
}