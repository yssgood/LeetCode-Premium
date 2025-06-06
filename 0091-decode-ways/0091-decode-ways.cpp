class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(); 
        vector<int> dp(n+1,0); 
        dp[0] = 1; 
        for(int i = 1; i <= n; i++){
            int onesDigit = s[i-1] - '0'; 
            if(onesDigit >= 1 && onesDigit <= 9){
                dp[i] += dp[i-1]; 
            }

            if(i - 2 >= 0){
                int twoDigit = stoi(s.substr(i-2,2)); 
                if(twoDigit >= 10 && twoDigit <= 26){
                    dp[i] += dp[i-2]; 
                }
            }
        }

        return dp[n]; 
    }
};