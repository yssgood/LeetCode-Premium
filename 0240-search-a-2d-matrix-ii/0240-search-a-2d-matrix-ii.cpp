class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1; 
        int col = 0; 
        
        while(row >= 0 && col < matrix[0].size()-1){
            
            if(matrix[row][col] > target){
                row--; 
            } else if(matrix[row][col] < target){
                col++; 
            } else{
                return true;
            }
        }
        return false; 
    }
};