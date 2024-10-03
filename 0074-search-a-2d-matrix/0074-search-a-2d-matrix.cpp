class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[matrix.size()-1][matrix[matrix.size()-1].size()-1] < target) return false; 
        int left = 0, right = matrix.size()-1; 
        int pivot = 0; 
        while(left <= right){
            int mid = (right + left) / 2; 
            
            int leftMost = matrix[mid][0], rightMost = matrix[mid][matrix[mid].size()-1]; 
            if(leftMost <= target && rightMost >= target){
                pivot = mid;
                break; 
            } else if(leftMost > target){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }
        left = 0;  
        right = matrix[0].size()-1; 
        while(left <= right){
            int mid = (right + left) / 2; 
            if(matrix[pivot][mid] == target){
                return true; 
            }

            if(matrix[pivot][mid] > target){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }

        return false; 
    }
};