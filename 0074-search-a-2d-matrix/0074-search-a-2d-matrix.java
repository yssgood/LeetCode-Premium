class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int left = 0, right = matrix.length-1; 
        int targetIndex = 0; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            int leftMost = matrix[mid][0]; 
            int rightMost = matrix[mid][matrix[0].length-1]; 

            if(leftMost > target){
                right = mid - 1; 
            } else if(rightMost < target){
                left = mid + 1; 
            } else{
                targetIndex = mid;
                break; 
            }
        }

        left = 0; 
        right = matrix[0].length-1; 
        while(left <= right){
            int mid = left + (right - left) / 2; 

            if(matrix[targetIndex][mid] == target){
                return true; 
            }

            if(matrix[targetIndex][mid] > target){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }


        return false; 
    }
}