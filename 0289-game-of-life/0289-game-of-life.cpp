class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(); 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbors = 0; 
                for(pair<int,int>& p : dir){
                    int nX = i + p.first; 
                    int nY = j + p.second; 

                    if(nX >= 0 && nX < m && nY >= 0 && nY < n && (board[nX][nY] == 1 || board[nX][nY] == 3)) neighbors++; 
                }
                
                if(board[i][j] == 1){
                    if(neighbors < 2 || neighbors > 3) board[i][j] = 3; // alive → dead (encode as 3)
                }
                if(board[i][j] == 0 && neighbors == 3){
                    board[i][j] = 2; // dead → alive (encode as 2)
                }
            }
        }

        // decode states
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2) board[i][j] = 1; // was dead, now alive
                else if(board[i][j] == 3) board[i][j] = 0; // was alive, now dead
            }
        }
    }
};