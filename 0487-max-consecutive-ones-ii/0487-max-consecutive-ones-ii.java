class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int k = 1; 
        int answer = 0; 
        int start = 0, end = 0; 
        while(end < nums.length){
            k -= nums[end] == 0 ? 1 : 0; 
            while(k < 0){
                k += nums[start++] == 0 ? 1 : 0; 
            }
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }
        return answer;
    }
}