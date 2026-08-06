class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int consecutive = 0; 
        int answer = 0;
        for(int n : nums){
            if(n == 0) consecutive = 0; 
            else consecutive++; 
            answer = Math.max(answer,consecutive); 
        }
        return answer; 
    }
}