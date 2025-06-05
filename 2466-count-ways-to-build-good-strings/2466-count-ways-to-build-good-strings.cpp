class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high+1,0); 
        dp[0] = 1; 
        for(int i = 1; i <= high; i++){
            if(i - zero >= 0) dp[i] = (dp[i] + dp[i-zero]) % MOD; 
            if (i - one >= 0)  dp[i] = (dp[i] + dp[i - one]) % MOD;
        }

        int answer = 0; 
        for(int i = low; i <= high; i++){
            answer = (answer + dp[i]) % MOD; 
        }
        return answer; 
    }
};