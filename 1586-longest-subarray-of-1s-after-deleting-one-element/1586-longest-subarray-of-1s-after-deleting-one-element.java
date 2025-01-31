class Solution {
    public int longestSubarray(int[] nums) {
        int chance = 1; 
        int answer = 0; 
        int start = 0, end = 0; 
        while(end < nums.length){
            chance -= (nums[end] == 0) ? 1 : 0; 
            while(chance < 0){
                chance += (nums[start++] == 0) ? 1 : 0; 
            }
            answer = Math.max(answer, end - start); 
            end++; 
        }

        return answer; 
    }
}