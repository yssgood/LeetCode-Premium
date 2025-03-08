class Solution {
public:
    string longestPalindrome(string s) {
        //babad 
        //baba -> longestPalindrome(0,n-1)
        //abad -> longestPalindrome(1,n); 
        //aba -> longestPalindrome(0+1,n-1); 

        //b a b a d 
        //1 1 1 1 1 

        //2 2 1 2 2
        int m = s.length(); 
        vector<vector<bool>> dp(m,vector<bool>(m,0)); 
        vector<int> answer = {0,0}; 
        for(int i = 0; i < m; i++){
            dp[i][i] = true; 
        }

        //c b b d 
        //1 1 1 1 
        
        for(int i = 0; i < m - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true; 
                answer = {i,i+1}; 
            }
        }

        for(int diff = 2; diff < m; diff++){
            for(int i = 0; i < m - diff; i++){
                int j = i + diff; 
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true; 
                    answer = {i,j}; 
                }
            }
        }

        int i = answer[0]; 
        int j = answer[1]; 

        return s.substr(i,j-i+1); 

    }
};