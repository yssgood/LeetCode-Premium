class Solution {
    public int longestOnes(int[] nums, int k) {
        int start = 0, end = 0; 
        int answer = 0; 
        while(end < nums.length){
            k -= nums[end] == 0 ? 1 : 0; 
            if(k < 0){
                k += nums[start++] == 0 ? 1 : 0; 
            }
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
}