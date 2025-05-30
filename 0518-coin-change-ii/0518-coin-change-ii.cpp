class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1)); 

        for(int i = 0; i <= n; i++){
            dp[i][0] = 1; 
        }
        
        for(int i = 1; i <= n; i++){
            int coin = coins[i-1]; 
            for(int j = 0; j <= amount; j++){
                dp[i][j] = dp[i-1][j]; 
                if(j >= coin){
                    dp[i][j] += dp[i][j - coin]; 
                }
            }
        }

        return dp[n][amount]; 
    }
};