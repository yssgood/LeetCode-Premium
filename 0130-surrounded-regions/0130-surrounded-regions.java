class Solution {
    public void dfs(char[][] board, int i, int j){
        if(i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] == 'X' || board[i][j] == 'S') return; 

        board[i][j] = 'S'; 
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1); 
    }
    public void solve(char[][] board) {
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(i == 0 || i == board.length-1 || j == 0 || j == board[0].length-1){
                    dfs(board,i,j); 
                }
            }
        }

        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[i].length; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O'; 
                } else{
                    board[i][j] = 'X'; 
                }
            }
        }
    }
}