class Solution {
    public void gameOfLife(int[][] board) {
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int m = board.length, n = board[0].length; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int liveCells = 0; 
                for(int[] d : dir){
                    int nX = d[0] + i; 
                    int nY = d[1] + j; 

                    if(nX >= 0 && nY >= 0 && nX < m && nY < n){
                        if(board[nX][nY] >= 1) liveCells++; 
                    }
                }

                if(board[i][j] == 1){
                    if(liveCells < 2 || liveCells > 3) board[i][j] = 2; 
                }
                if(board[i][j] == 0){
                    if(liveCells == 3) board[i][j] = -1; 
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2) board[i][j] = 0; 
                if(board[i][j] == -1) board[i][j] = 1; 
            }
        }
    }
}