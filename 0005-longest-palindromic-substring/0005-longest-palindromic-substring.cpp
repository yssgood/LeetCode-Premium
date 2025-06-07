class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); 
        if(n <= 1) return s;  

        vector<vector<int>> dp(n,vector<int>(n,0)); 
        int max_len = 1; 
        int index = 0; 
        for(int i = 0; i < n; i++) dp[i][i] = 1; 
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                max_len = 2; 
                index = i; 
                dp[i][i+1] = 2; 
            }
        }

        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1; 
                if(s[i] == s[j] && dp[i+1][j-1]){
                    index = i; 
                    max_len = len; 
                    dp[i][j] = len; 
                }
            }
        }

        return s.substr(index, max_len); 
    }
};