class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length; 
        int n = grid[0].length; 
        int[][] matrix = new int[m][n]; 
        matrix[0][0] = grid[0][0]; 
        for(int j = 1; j < n; j++){
            matrix[0][j] = matrix[0][j-1] + grid[0][j]; 
        }
        for(int i = 1; i < m; i++){
            matrix[i][0] = matrix[i-1][0] + grid[i][0]; 
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                matrix[i][j] = Math.min(matrix[i-1][j], matrix[i][j-1]) + grid[i][j]; 
            }
        }

        return matrix[m-1][n-1]; 
    }
}