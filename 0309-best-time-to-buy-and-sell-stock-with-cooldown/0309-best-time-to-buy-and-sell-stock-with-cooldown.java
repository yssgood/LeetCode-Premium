class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 1) return 0; 
        int[] dp = new int[prices.length]; 
        dp[0] = 0; 
        dp[1] = Math.max(prices[1] - prices[0], 0); 
        int max_diff = Math.max(-prices[0],-prices[1]); 
        
        for(int i = 2; i < prices.length; i++){
            dp[i] = Math.max(dp[i-1], prices[i] + max_diff); 
            max_diff = Math.max(max_diff, dp[i-2] - prices[i]); 
        }
        
        
        return dp[prices.length-1]; 
    }
}