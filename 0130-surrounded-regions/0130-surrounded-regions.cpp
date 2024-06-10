class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i <0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return; 
        board[i][j] = 'A';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1) ; 
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1){
                    if(board[i][j] == 'O') dfs(board,i,j); 
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                } else{
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};