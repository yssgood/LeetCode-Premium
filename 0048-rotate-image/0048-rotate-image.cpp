class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] > 0){
                    int save = matrix[i][j]; 
                    matrix[i][j] = matrix[j][i] * -1; 
                    matrix[j][i] = save * -1; 
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                matrix[i][j] *= -1; 
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end()); 
        }
    }
};