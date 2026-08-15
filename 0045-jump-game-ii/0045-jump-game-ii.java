class Solution {
    public int jump(int[] nums) {
        if(nums.length == 1) return 0; 
        int answer = 0; 
        int currJump = 0; 
        int currMax = 0; 

        for(int i = 0; i < nums.length; i++){
            currMax = Math.max(currMax, i + nums[i]); 
            if(i >= currJump){
                answer++;
                currJump = currMax; 
                if(currJump >= nums.length-1) return answer;  
            }
        }
        return -1; 
    }
}