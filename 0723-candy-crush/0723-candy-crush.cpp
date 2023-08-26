class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool flag = true; 
        while(flag){
          vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(), false)); 
          flag = false; 
          for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size() - 2; j ++){
              if(board[i][j] != 0 && (board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2])){
                visited[i][j] = true; 
                visited[i][j+1] = true; 
                visited[i][j+2] = true;
                flag = true; 
              }
            }
          }

          for(int i = 0; i < board.size() - 2; i++){
            for(int j = 0; j < board[0].size(); j++){
              if(board[i][j] != 0 && (board[i][j] == board[i+1][j]) && (board[i][j] == board[i+2][j])){
                visited[i][j] = true; 
                visited[i+1][j] = true; 
                visited[i+2][j] = true; 
                flag = true; 
              }
            }
          }

          if(flag){
            for(int i = 0; i < visited.size(); i++){
              for(int j = 0; j < visited[0].size(); j++){
                if(visited[i][j] == true){
                  board[i][j] = 0; 
                  for(int k = i; k > 0; k--){
                    int swap = board[k-1][j]; 
                    board[k-1][j] = 0; 
                    board[k][j] = swap; 
                  }
                }
              }
            }
          }

          // for(int i = 0; i < board.size(); i++){
          //   for(int j = 0; j < board[i].size(); j++){
          //     cout << board[i][j] << ' '; 
          //   }
          //   cout << endl; 
          // }
        }

      return board; 
    }
};