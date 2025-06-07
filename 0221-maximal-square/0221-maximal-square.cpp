class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        vector<vector<int>> numMatrix(m, vector<int>(n,0)); 
        int max_area = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] - '0' > 0) max_area = 1; 
                numMatrix[i][j] = matrix[i][j] - '0'; 
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int top = numMatrix[i-1][j];
                int left = numMatrix[i][j-1]; 
                int cross = numMatrix[i-1][j-1]; 
                int curr = numMatrix[i][j]; 
                if(top && left && cross && curr){
                    numMatrix[i][j] = min({top,left,cross}) + 1;
                }
                    max_area = max(max_area, max(numMatrix[i][j], max(left,max(top,cross)))); 
            }
        }

        return max_area * max_area; 
    }
};