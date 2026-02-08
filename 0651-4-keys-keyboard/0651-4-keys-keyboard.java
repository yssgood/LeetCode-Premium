class Solution {
    public int maxA(int n) {
        if(n <= 3) return n; 
        int[] dp = new int[n+1]; 
        dp[1] = 1;
        dp[2] = 2; 
        dp[3] = 3; 

        for(int i = 4; i <= n; i++){
            //dp[i] = Math.max(dp[i-1] + 1, dp[i-3] * 2); 
            dp[i] = dp[i-1] + 1; 
            for(int j = 1; j <= i - 3; j++){
                dp[i] = Math.max(dp[i], dp[j] * (i - j - 1)); 
            }
        }
        //ctrlv = dp[i-2] * 2 
        //ctrla = dp[i-1]; 
        //ctrlc = dp[i-2]; 

        //max 는 adding A or pressing ctrlV 
        return dp[n]; 
    }
}