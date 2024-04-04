class Solution {
    bool visited[7][7];
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(index >= word.length()) return true; 
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) return false; 
        visited[i][j] = true; 
        bool flag = (dfs(board,word,i+1,j,index+1) || dfs(board,word,i-1,j,index+1) || dfs(board,word,i,j+1,index+1)|| dfs(board, word, i, j-1, index+1));
        visited[i][j] = false; 
        return flag; 
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0)){
                    return true; 
                }
            }
        }
        return false; 
    }
};