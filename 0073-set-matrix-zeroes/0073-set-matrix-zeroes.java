class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length; 
        boolean flag1 = false; 
        boolean flag2 = false; 
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0) flag1 = true; 
        }
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) flag2 = true; 
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0; 
                    matrix[i][0] = 0; 
                }
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0; 
                }
            }
        }

        for(int j = 0; j < n; j++){
            if(flag1) matrix[0][j] = 0; 
        }
        for(int i = 0; i < m; i++){
            if(flag2) matrix[i][0] = 0; 
        }
    }
}