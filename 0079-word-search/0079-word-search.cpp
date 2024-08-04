class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index){
        if(index >= word.length()){
            return true; 
        }
        if(i  < 0  || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false; 
        }

        char tmp = board[i][j]; 
        board[i][j] = '-'; 

        bool flag = (dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1));

        board[i][j] = tmp;  
        return flag; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0)){
                    return true; 
                }
            }
        }
        return false; 
    }
};