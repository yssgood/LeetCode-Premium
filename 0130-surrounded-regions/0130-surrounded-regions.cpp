class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<char>>& visited){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return; 

        board[i][j] = 'A';
        dfs(board,i+1,j,visited);
        dfs(board,i-1,j,visited);
        dfs(board,i,j+1,visited);
        dfs(board,i,j-1,visited); 
    }
    void solve(vector<vector<char>>& board) {
       vector<vector<char>> visited(board.size(), vector<char>(board[0].size(),'X')); 

       for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(i == 0 && board[i][j] == 'O' || i == board.size()-1 && board[i][j] == 'O' ){
                dfs(board,i,j,visited); 
            }

            if(j == 0 && board[i][j] == 'O' || j == board[0].size()-1 && board[i][j] == 'O' ){
                dfs(board,i,j,visited); 
            } 
        }
       }

       for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X'; 
            }

            if(board[i][j] =='A'){
                board[i][j] = 'O'; 
            }
        }
       }

       
    }
};