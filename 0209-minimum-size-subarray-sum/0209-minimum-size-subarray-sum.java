class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start = 0, end = 0; 
        int answer = Integer.MAX_VALUE; 
        int sum = 0; 
        while(end < nums.length){
            sum += nums[end]; 
            while(sum >= target){
                answer = Math.min(answer, end - start + 1); 
                sum -= nums[start++]; 
            }
            end++; 
        }
        return answer == Integer.MAX_VALUE ? 0 : answer; 
    }
}