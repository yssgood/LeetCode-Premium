class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(); 
        vector<set<char>> rows(n); 
        vector<set<char>> cols(n); 
        vector<set<char>> boxes(n); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') continue; 

                char digit = board[i][j]; 

                int boxIndex = (i / 3) * 3 + (j / 3); 

                if(rows[i].count(digit) || cols[j].count(digit) || boxes[boxIndex].count(digit)){
                    return false; 
                }

                rows[i].insert(digit);
                cols[j].insert(digit); 
                boxes[boxIndex].insert(digit); 
            }
        }
        return true; 
    }
};