class Solution {
    public int jump(int[] nums) {
        int maxJump = 0; 
        int currJump = 0; 
        int jump = 0; 

        for(int i = 0; i < nums.length-1; i++){
            maxJump = Math.max(maxJump, i + nums[i]); 
            if(i == currJump){
                currJump = maxJump; 
                jump++; 
                if(currJump >= nums.length-1) return jump; 
            }
        }
        return jump; 
    }
}