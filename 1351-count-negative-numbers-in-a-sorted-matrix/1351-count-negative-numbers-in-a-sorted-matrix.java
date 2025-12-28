class Solution {
    public int countNegatives(int[][] grid) {
        int m = grid.length, n = grid[0].length;  
        int count = 0; 
        for(int i = 0; i < m; i++){
            int negativeIndex = binarySearch(grid,i); 
            if(negativeIndex != -1) count += n - negativeIndex; 
        }
        return count; 
    }
    public int binarySearch(int[][] grid, int index){
        int left = 0, right = grid[0].length; 
        int candidate = -1; 
        while(left < right){
            int mid = left + (right - left) / 2; 
            if(grid[index][mid] < 0){
                candidate = mid; 
                right = mid; 
            } else{
                left = mid + 1; 
            }
        }
        return candidate; 
    }
}