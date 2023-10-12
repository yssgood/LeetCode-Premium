class Solution {

bool answer = false; 

public:
    bool dfs(string& word, vector<vector<char>>& board, int i, int j, int index,vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || visited[i][j] || board[i][j] != word[index] ) return false; 
        if(index >= word.length()-1){
            return true; 
        }

        visited[i][j] = true;
        bool flag = (dfs(word,board,i+1,j,index+1,visited) || dfs(word,board,i-1,j,index+1,visited) || dfs(word,board,i,j+1,index+1,visited) || dfs(word,board,i,j-1,index+1,visited)); 
        visited[i][j] = false;

        return flag; 
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false)); 
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(word,board,i,j,0,visited)){
                    return true; 
                }
            }
        }

        return false; 
    }
};

// class Solution {
//     int N, M; 
//     bool flag = false; 
// public:
//     bool dfs(int i, int j, int cnt, string& word, vector<vector<bool>>& visited,vector<vector<char>>& board){
//         if(i < 0 || j < 0 || i >= N || j >= M || visited[i][j] || board[i][j] != word[cnt]) return false; 
//         if(cnt == word.length()-1) return true; 
        
//         visited[i][j] = true; 
//         flag = (dfs(i+1,j,cnt+1,word,visited,board) || dfs(i-1,j,cnt+1,word,visited,board) || dfs(i,j+1,cnt+1,word,visited,board) || dfs(i,j-1,cnt+1,word,visited,board)); 
//         visited[i][j] = false; 
//         return flag; 
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         N = board.size(), M = board[0].size(); 
//         vector<vector<bool>> visited(N,vector<bool>(M,false)); 
//         for(int i = 0; i < board.size(); i++){
//             for(int j = 0; j < board[i].size(); j++){
//                 if(board[i][j] == word[0] && dfs(i,j,0,word,visited,board)) return true; 
//             }
//         }
//         return false; 
//     }
// };