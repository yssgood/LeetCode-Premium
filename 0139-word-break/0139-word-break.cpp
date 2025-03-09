class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(); 
        vector<bool> dp(n); 

        for(int i = 0; i < s.length(); i++){
            for(string word : wordDict){
                if(i < word.length() -1){
                    continue; 
                }

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