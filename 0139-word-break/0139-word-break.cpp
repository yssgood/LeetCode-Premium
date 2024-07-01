class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false); 
        for(int i = 0; i < s.length(); i++){
            for(string& word : wordDict){
                if(i < word.length() -1) continue; 
                if(i == word.length()-1 || dp[i - word.length()]){
                    if(s.substr(i - word.length() + 1, word.length()) == word){
                        dp[i] = true; 
                        break; 
                    }
                }
            }
        }

        return dp[s.length()-1]; 

    }
};