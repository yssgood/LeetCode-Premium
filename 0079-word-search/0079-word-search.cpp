class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index){
        if(index >= word.length()) return true; 

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) return false; 

        bool flag = true; 
        char curr = board[i][j]; 
        board[i][j] = '-'; 
        flag = (dfs(board,i+1,j,word,index+1) || dfs(board,i-1,j,word,index+1) || dfs(board,i,j+1,word,index+1) || dfs(board,i,j-1,word,index+1)); 

        board[i][j] = curr; 

        return flag; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        //for() for() -> dfs() 
        //x y -> !visited -> word[0] 
        //vector<pair<int,int>> dir -> dfs() 
        //if curr_index >= word.length() 

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,i,j,word,0)){
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
};