class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s.substr(0,1); 
        
        int n = s.length(); 
        int index = 0, max_len = 1; 
        vector<vector<bool>> dp(n,vector<bool>(n,false)); 

        for(int i = 0; i < n; i++){
            dp[i][i] = true; 
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true; 
                max_len = 2; 
                index = i; 
            }
        }

        for(int length = 2; length < n; length++){
            for(int i = 0; i < n - length; i++){
                int j = i + length;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true; 
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1; 
                        index = i; 
                    }
                }
            }
        }

        return s.substr(index, max_len); 
    }
};