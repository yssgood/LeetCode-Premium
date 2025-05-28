class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));
        
        // Base case: 1 way to make amount 0 with any number of coins
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= amount; j++) {
                // Don't use coin i-1
                dp[i][j] = dp[i-1][j];
                
                // Use coin i-1 (if possible)
                if(j >= coins[i-1]) {
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
        }
        
        return (int)dp[n][amount];
    }
};