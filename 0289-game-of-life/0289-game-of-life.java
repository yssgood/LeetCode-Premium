class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length, n = board[0].length; 
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; 


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int count = 0; 

                for(int k = 0; k < 8; k++){
                    int nX = i + dir[k][0]; 
                    int nY = j + dir[k][1]; 

                    if(nX < 0 || nY < 0 || nX >= m || nY >= n) continue; 

                    if(board[nX][nY] > 0) count++; 
                }

                if(board[i][j] == 0){
                    if(count == 3) board[i][j] = -1; 
                }
                if(board[i][j] > 0){
                    if(count < 2 || count > 3) board[i][j] = 2; 
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1) board[i][j] = 1; 
                if(board[i][j] == 2) board[i][j] = 0; 
            }
        }
    }
}