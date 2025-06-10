class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length; 
        if(n <= 1) return 1; 
        
        int[] dp = new int[n]; 
        int max_ =  1; 
        Arrays.fill(dp,1); 

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = Math.max(dp[i], dp[j] + 1); 
                    max_ = Math.max(max_, dp[i]); 
                }
            }
        }

        return max_; 
    }
}