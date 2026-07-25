class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length; 
        for(int i = 0; i < m; i++){
            int[] candidate = matrix[i]; 
            if(candidate[0] <= target && candidate[candidate.length-1] >= target){
                int left = 0, right = candidate.length-1; 
                while(left <= right){
                    int mid = left + (right - left) / 2; 
                    if(candidate[mid] == target) return true; 

                    if(candidate[mid] > target) right = mid - 1;
                    else left = mid + 1; 
                }
            }
        }

        return false; 
    }
}