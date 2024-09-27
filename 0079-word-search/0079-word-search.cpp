class Solution {
public:
    bool dfs(int i, int j, int index,string word, vector<vector<char>>& board){
        if(index >= word.length()) return true; 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) return false; 
        char save = board[i][j]; 
        board[i][j] = '-'; 
        bool flag = (dfs(i + 1, j, index + 1, word, board) || dfs(i - 1, j, index +1, word, board)|| dfs(i, j +1, index +1, word, board) ||dfs(i, j-1,index+1,word,board)); 

        board[i][j] = save; 

        return flag; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(i,j,0,word,board)){
                    return true; 
                }
            }
        }

        return false; 
    }
};