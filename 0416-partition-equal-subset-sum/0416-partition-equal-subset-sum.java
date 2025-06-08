class Solution {
    public boolean canPartition(int[] nums) {
        //1+5+11+5 = 22 (11) 
        //1+2+3+5 = 11
        int totalSum = 0; 
        for(int n : nums) totalSum += n; 
        if(totalSum % 2 != 0) return false;
        
        int target = totalSum / 2; 
        boolean[] dp = new boolean[target+1]; 

        dp[0] = true; 

        for(int num : nums){
            for(int sum = target; sum >= num; sum--){
                dp[sum] = dp[sum] || dp[sum-num]; 
            }
        }

        // for(int i = 1; i <= target; i++){
        //     for(int n : nums){
                
        //     }
        // }


        return dp[target];
    }
}


//[1,2,3] 