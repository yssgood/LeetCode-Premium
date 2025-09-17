class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        vector<int> dp(amount+1,INT_MAX-1); 
        dp[0] = 0; 
        for(int i = 0; i < n; i++){
            int currCoin = coins[i]; 
            for(int j = 1; j <= amount; j++){
                if(j >= currCoin){
                    dp[j] = min(dp[j], dp[j - currCoin] + 1); 
                }
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount]; 
    }
};