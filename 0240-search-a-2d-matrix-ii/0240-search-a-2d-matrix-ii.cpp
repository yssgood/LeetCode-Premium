class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0; i < matrix.size(); i++){
            
            int first = matrix[i][0]; 
            int last = matrix[i][matrix[i].size()-1]; 

            //vector<int> curr = matrix[i]; 
            
            if(first <= target && last >= target){
                int start = 0; 
                int end = matrix[i].size()-1; 

                while(start <= end){
                    int mid = (end + start) / 2;  

                    if(matrix[i][mid] == target){
                        return true; 
                    } else if(matrix[i][mid] < target){
                        start = mid + 1; 
                    } else{
                        end = mid - 1; 
                    }
                }
            }
        }

        return false; 
    }
};