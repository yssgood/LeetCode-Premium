class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'X') return; 

        board[i][j] = '.'; 
        dfs(board, i+1, j);
        dfs(board, i-1, j); 
        dfs(board, i, j + 1);
        dfs(board, i, j -1); 
    }
    int countBattleships(vector<vector<char>>& board) {
        int answer = 0; 

        int m = board.size(), n = board[0].size(); 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    dfs(board,i,j); 
                    answer++; 
                }
            }
        }

        return answer; 
    }
};