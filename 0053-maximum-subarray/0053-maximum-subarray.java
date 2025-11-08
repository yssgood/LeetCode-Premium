class Solution {
    public int maxSubArray(int[] nums) {
        int answer = nums[0]; 
        int curr = nums[0]; 
        for(int i = 1; i < nums.length; i++){
            int sum = curr + nums[i]; 
            curr = Math.max(nums[i],sum); 
            answer = Math.max(answer, curr); 
        }
        return answer; 
    }
}