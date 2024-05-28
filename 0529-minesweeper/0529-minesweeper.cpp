class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}}; 
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board; 
        }

        queue<pair<int,int>> q; 
        q.push({click[0],click[1]}); 

        while(!q.empty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                pair<int,int> p = q.front();
                q.pop(); 

                int mines = 0; 
                int x = p.first, y = p.second; 

                for(pair<int,int>& d : dir){
                    int nX = p.first + d.first; 
                    int nY = p.second + d.second; 

                    if(nX < 0 || nY < 0 || nX >= board.size() || nY >= board[0].size() || board[nX][nY] == 'B') continue; 

                    if(board[nX][nY] == 'M'){
                        mines++; 
                    }
                }

                if(mines > 0){
                    board[x][y] = mines + '0'; 
                } else{
                    board[x][y] = 'B';  
                    for(pair<int,int>& d : dir){
                        int nX = p.first + d.first; 
                        int nY = p.second + d.second; 

                        if(nX < 0 || nY < 0 || nX >= board.size() || nY >= board[0].size() || board[nX][nY] == 'B') continue; 

                        q.push({nX,nY}); 
                        board[nX][nY] = 'B'; 
                    }
                }
            }
        }

        return board; 
    }
};
