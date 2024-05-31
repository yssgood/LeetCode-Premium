class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer; 

        int top = 0, left = 0, right = matrix[0].size()-1, bottom = matrix.size()-1; 
        int dir = 0; 

        while(answer.size() < matrix.size() * matrix[0].size()){
            if(dir == 0){ //to the right 
                for(int i = left; i <= right; i++){
                    answer.push_back(matrix[top][i]); 
                }
                top++; 
                dir = 1; 
            }  else if(dir == 1){ //to the bottom 
                for(int i = top; i <= bottom; i++){
                    answer.push_back(matrix[i][right]); 
                }
                right--; 
                dir = 2; 
            } else if(dir == 2){ //to the left 
                for(int j = right; j >= left; j--){
                    answer.push_back(matrix[bottom][j]); 
                }
                bottom--;
                dir = 3; 
            } else if(dir = 3){ //to the top 
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