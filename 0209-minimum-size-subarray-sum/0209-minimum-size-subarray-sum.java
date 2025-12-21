class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int currSum = 0; 
        int answer = Integer.MAX_VALUE; 
        int start = 0, end = 0; 
        int n = nums.length; 
        while(end < n){
            currSum += nums[end]; 
            while(currSum >= target){
                answer = Math.min(answer, end - start + 1); 
                currSum -= nums[start++]; 
            }
            end++; 
        }
        return answer == Integer.MAX_VALUE ? 0 : answer; 
    }
}