class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int index){
        if(index >= word.length()) return true; 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) return false;

        char tmp = board[i][j]; 
        board[i][j] =  '-'; 

        bool flag = (dfs(board,i+1,j,word,index+1) || dfs(board,i-1,j,word,index+1) || 
        dfs(board,i,j+1,word,index+1) || dfs(board,i,j-1,word,index+1));
        
        board[i][j] = tmp; 

        return flag; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && dfs(board,i,j,word,0)){
                    return true; 
                }
            }
        }

        return false; 
    }
};
