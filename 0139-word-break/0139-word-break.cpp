class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(),false); 
        for(int i = 0; i < s.length(); i++){
            for(string& ss : wordDict){
                if(i < ss.length()-1){
                    continue; 
                }

                if(i == ss.length()-1 || dp[i - ss.length()]){
                    if(s.substr(i - ss.length() + 1, ss.length()) == ss){
                        dp[i] = true; 
                    }
                }
            }
        }


        return dp[s.length()-1]; 
    }
};