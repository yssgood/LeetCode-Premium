class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer; 
        int dir = 0; 
        int top = 0, right = matrix[0].size()-1, bottom = matrix.size()-1, left = 0; 
        while(top <= bottom && left <= right){
            if(dir == 0){
                for(int i = left; i <= right; i++){
                    answer.push_back(matrix[top][i]); 
                }
                top++; 
                dir = 1; 
            } else if(dir == 1){
                for(int i = top; i <= bottom; i++){
                    answer.push_back(matrix[i][right]); 
                }
                right--; 
                dir = 2; 
            } else if(dir == 2){
                for(int i = right; i >= left; i--){
                    answer.push_back(matrix[bottom][i]); 
                }
                bottom--;
                dir = 3;  
            } else if(dir == 3){
                for(int i = bottom; i >= top; i--){
                    answer.push_back(matrix[i][left]); 
                }
                left++;
                dir = 0; 
            }
        }

        return answer; 
    }
};