class Solution {
public:
    void fall(vector<vector<int>>& tmpBoard, int x, int y){

        for(int i = x; i > 0; i--){
            int save = tmpBoard[i-1][y]; 
            tmpBoard[i][y] = save; 
            tmpBoard[i-1][y] = 0; 
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool flag = true; 
        while(flag){
            flag = false; 
            vector<vector<int>> tmpBoard = board; 
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size()-2; j++){
                    int left = board[i][j], middle = board[i][j+1], right = board[i][j+2];  
                    if(left != 0 && left == middle && middle == right){
                        tmpBoard[i][j] = 0; 
                        tmpBoard[i][j+1] = 0; 
                        tmpBoard[i][j+2] = 0; 
                        flag = true; 
                    }
                }
            }

            for(int i = 0; i < board.size()-2; i++){
                for(int j = 0; j < board[0].size(); j++){
                    int left = board[i][j], mid_bottom = board[i+1][j], bottom = board[i+2][j]; 
                    if(left != 0 && left == mid_bottom && mid_bottom == bottom){
                        tmpBoard[i][j] = 0;
                        tmpBoard[i+1][j] = 0;
                        tmpBoard[i+2][j] = 0;
                        flag = true; 
                    }
                }
            }

            for(int i = 1; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(tmpBoard[i][j] == 0){
                        fall(tmpBoard,i,j); 
                    }
                }
            }



            board = tmpBoard; 
            if(!flag) break; 
        }

        return board; 
    }
};

//[[110,0,0,0,0],
// [210,0,0,113,114],
// [310,0,0,213,214],
// [410,0,112,313,314],
// [5,5,5,5,414],
// [610,211,3,3,3],
// [710,311,412,613,614],
// [810,411,512,713,714],
// [1,1,1,1,1],
// [4,4,4,4,1014]]...