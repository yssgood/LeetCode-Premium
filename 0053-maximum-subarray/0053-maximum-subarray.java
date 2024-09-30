class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = nums[0]; 
        int answer = nums[0]; 
        for(int i = 1; i < nums.length; i++){
            currSum = Math.max(currSum + nums[i], nums[i]); 
            answer = Math.max(currSum, answer); 
            //System.out.println(currSum); 
        }
        return answer; 
    }
}