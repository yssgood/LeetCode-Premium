class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> container; 
        int m = board.size(), n = board[0].size(); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int neighbors = 0; 
                for(pair<int,int>& p : dir){
                    int nX = i + p.first; 
                    int nY = j + p.second; 

                    if(nX >= 0 && nX < m && nY >= 0 && nY < n && board[nX][nY] == 1) neighbors++; 
                }
                if(board[i][j] == 1){
                    if(neighbors < 2) container.push_back({i,j,0});
                    if(neighbors > 3) container.push_back({i,j,0}); 
                }
                if(board[i][j] == 0 && neighbors == 3){
                    container.push_back({i,j,1}); 
                }
            }
        }

        for(vector<int>& v : container){
            int x = v[0], y = v[1], cell =v[2]; 
            board[x][y] = cell; 
        }
    }
};