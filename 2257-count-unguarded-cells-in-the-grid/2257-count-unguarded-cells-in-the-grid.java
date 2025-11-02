class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] matrix = new int[m][n]; 
        int[][] dir = {{0,-1},{0,11},{1,0},{-1,0}}; 
        for(int[] w : walls) matrix[w[0]][w[1]] = -1; 
        for(int[] g : guards) matrix[g[0]][g[1]] = 1; 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    
                    for(int[] d : dir){
                        int nX = i + d[0]; 
                        int nY = j + d[1]; 
                        while(nX >= 0 && nY >= 0 && nX < m && nY < n && matrix[nX][nY] == 0){
                            matrix[nX][nY] = 2; 
                            nX += d[0]; 
                            nY += d[1]; 
                        }
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                System.out.print(matrix[i][j] + " "); 
            }
            System.out.println(); 
        }

        return 1; 
    }
}