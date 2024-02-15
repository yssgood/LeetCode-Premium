class Solution {

int N,M; 
public:
    bool check(int i, int j, int flag, vector<vector<int>>& board){
        if(flag == 0) return (i + 1 < N && i + 2 < N && board[i][j] != 0 && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]); 
        return (j + 1 < M && j + 2 < M && board[i][j] != 0 && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2]); 
    }

    void dropTop(int x, int y, vector<vector<int>>& board){
        for(int i = x; i >= 0; i--){
            //board[i][y] = 0; 
            if(i - 1 >= 0){
                board[i][y] = board[i-1][y];
                board[i-1][y] = 0; 
            } else{
                board[i][y] = 0; 
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        //vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false)); 
        bool visited[51][51]; 
        N = board.size(), M = board[0].size(); 
        bool flag = true; 

        while(flag){
            flag = false; 

            memset(visited,false,sizeof(visited)); 
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(check(i,j,0, board)){
                        visited[i][j] = true;
                        visited[i+1][j] = true; 
                        visited[i+2][j] = true; 
                    }

                    if(check(i,j,1, board)){
                        visited[i][j] = true;
                        visited[i][j+1] = true;
                        visited[i][j+2] = true; 
                    }
                }
            }

            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(visited[i][j]){
                        flag = true; 
                        dropTop(i,j,board); 
                    }
                }
            }

    

        }
        return board; 
    }
};

