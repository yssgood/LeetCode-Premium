class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int answer = 0; 
        int count = 0; 
        for(int n : nums){
            count = n == 1 ? count + 1 : 0; 
            answer = Math.max(answer,count); 
        }
        return answer; 
    }
}