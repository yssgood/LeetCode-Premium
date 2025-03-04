class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); 
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int left = (j - 1 < 0) ? INT_MAX : matrix[i-1][j-1]; 
                int top = matrix[i-1][j]; 
                int right = (j + 1 >= matrix[i].size()) ? INT_MAX : matrix[i-1][j+1]; 
                matrix[i][j] = min(left,min(top,right)) + matrix[i][j]; 
            }
        }

        return *min_element(matrix[m-1].begin(), matrix[m-1].end());
    }
};