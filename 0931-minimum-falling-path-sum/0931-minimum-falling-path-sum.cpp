class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int left = (j - 1 < 0) ? 100000 : matrix[i-1][j-1]; 
                int middle = matrix[i-1][j]; 
                int right = (j + 1 >= n) ? 100000 : matrix[i-1][j+1]; 
                matrix[i][j] = min(left,min(middle,right)) + matrix[i][j]; 
            }
        }
        return *min_element(matrix[n-1].begin(), matrix[n-1].end()); 
    }
};