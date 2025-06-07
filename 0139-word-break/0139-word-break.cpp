class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n); 
        for(int i = 0; i < n; i++){
            for(string& word : wordDict){
                int length = word.length(); 
                if(i - (length - 1) < 0) continue; 

                if(i == length-1 || dp[i - length] == true){
                    if(s.substr(i - (length - 1), length) == word){
                        dp[i] = true; 
                    }
                }
            }
        }

        return dp[n-1]; 
    }
};