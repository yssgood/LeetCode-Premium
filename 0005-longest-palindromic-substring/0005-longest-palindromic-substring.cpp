class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s; 
        //b a b a d 
        int n = s.length(); 
        vector<vector<bool>> dp(n,vector<bool>(n,false)); 

        for(int i = 0; i < n; i++){
            dp[i][i] = true; 
        }

        int max_len = 0; 
        int index = 0; 

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true; 
                max_len = 1; 
                index = i; 
            }
        }

        for(int len = 2; len < n; len++){
            for(int i = 0; i < n - len; i++){
                int j = i + len;
                if(s[i] == s[j]){
                    if(dp[i+1][j-1]){
                        max_len = len; 
                        index = i; 
                        dp[i][j] = true; 
                    }
                }
            }
        }
        
        return s.substr(index,max_len + 1); 
    }
};