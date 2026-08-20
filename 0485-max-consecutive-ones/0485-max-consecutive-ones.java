class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int answer = 0; 
        int count = 0; 
        for(int i = 0; i < nums.length; i++){
            count += nums[i] == 1 ? 1 : -count; 
            answer = Math.max(answer,count); 
        }
        return answer; 
    }
}