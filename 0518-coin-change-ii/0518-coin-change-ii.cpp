class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<unsigned long long> dp(amount+1,0); 
        dp[0] = 1; 
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= amount; j++){
                if(j >= coins[i]){
                    dp[j] += dp[j - coins[i]]; 
                }
            }
        }
        return dp[amount]; 
    }
};