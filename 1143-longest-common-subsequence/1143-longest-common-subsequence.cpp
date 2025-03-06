class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //a b c c d e 
        //a c c d e 
        
        int m = text1.length(); 
        int n = text2.length(); 
        vector<vector<int>> lcs(m+1, vector<int>(n+1,0)); 

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1]; 
                } else{
                    lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]); 
                }
            }
        }
        return lcs[m][n]; 
    }
};