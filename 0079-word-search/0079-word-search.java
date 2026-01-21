class Solution {
    public boolean dfs(char[][] board, int i, int j, String word, int index){
        if(index >= word.length()) return true; 
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index)) return false; 

        char tmp = board[i][j]; 
        board[i][j] = '-'; 
        boolean flag = (dfs(board,i+1,j,word,index+1) || dfs(board,i-1,j,word,index+1) || dfs(board,i,j+1,word,index+1) || dfs(board,i,j-1,word,index+1)); 

        board[i][j] = tmp; 
        return flag; 
    }
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length; 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word.charAt(0) && dfs(board,i,j,word,0)) return true; 
            }
        }

        return false; 
    }
}