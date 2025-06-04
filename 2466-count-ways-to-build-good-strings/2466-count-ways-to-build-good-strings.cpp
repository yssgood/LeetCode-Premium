class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        
        // dp[i] = number of ways to build a string of length i
        vector<long long> dp(high + 1, 0);
        
        // Base case: empty string has 1 way to build (do nothing)
        dp[0] = 1;
        
        // Fill the DP table
        for (int i = 1; i <= high; i++) {
            // Option 1: Add 'zero' zeros to a string of length (i - zero)
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            
            // Option 2: Add 'one' ones to a string of length (i - one)  
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        
        // Sum up all valid lengths from low to high
        long long result = 0;
        for (int i = low; i <= high; i++) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};