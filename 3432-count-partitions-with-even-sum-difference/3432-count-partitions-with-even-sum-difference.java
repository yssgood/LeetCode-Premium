class Solution {
    public int countPartitions(int[] nums) {
        int[] suffix = new int[nums.length]; 
        int n = nums.length; 
        suffix[n-1] = nums[n-1]; 
        for(int i = n -2; i >= 0; i--){
            suffix[i] = suffix[i+1] + nums[i]; 
        }

        int prefix = nums[0]; 
        int count = 0; 
        for(int i = 1; i < n; i++){
            int sumDiff = prefix - suffix[i]; 
            if(sumDiff % 2 == 0){
                count++; 
            }
            prefix+=nums[i];
        }

        return count; 
    }
}