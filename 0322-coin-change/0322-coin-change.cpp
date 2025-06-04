class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0) return 0; 
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int>(amount+1,INT_MAX-1)); 

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0; 
        }

        for(int i = 1; i <= n; i++){
            int coin = coins[i-1]; 
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i-1][j]; 
                if(j >= coin){
                    dp[i][j] = min(dp[i][j],dp[i][j-coin] + 1); 
                }
            }
        }

        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount]; 
    }
};