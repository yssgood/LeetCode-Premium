class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        vector<vector<int>> dp(m,vector<int>(n,0)); 
        int max_ = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') max_ = 1; 
                dp[i][j] = matrix[i][j] - '0'; 
            }
        }

        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int top = dp[i-1][j]; 
                int cross = dp[i-1][j-1];
                int left = dp[i][j-1];
                
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(top,min(left,cross)) + 1; 
                    max_ = max(max_, dp[i][j]); 
                }
            }
        }

        return max_ * max_; 
    }
};