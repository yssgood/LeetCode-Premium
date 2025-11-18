class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n,false); 

        for(int i = 0; i < n; i++){
            for(string& ss : wordDict){
                if(i < ss.length() - 1) continue; 

                if(i == ss.length() -1 || dp[i - ss.length()]){
                    if(s.substr(i - ss.length() + 1, ss.length()) == ss){
                        dp[i] = true; 
                        break; 
                    }
                }
            }
        }

        return dp[n-1]; 
    }
};