class Solution {
    public int longestOnes(int[] nums, int k) {
        int start = 0, end = 0; 
        int answer = Integer.MIN_VALUE; 
        
        while(end < nums.length){
            if(nums[end] == 0) k--; 
            
            while(k < 0 && start < nums.length){
                if(nums[start] == 0) k++; 
                start++; 
            }

            
            answer = Math.max(answer, end - start + 1); 
            end++; 
        }


        return answer; 
    }
}