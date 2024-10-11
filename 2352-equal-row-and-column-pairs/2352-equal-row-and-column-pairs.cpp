class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int> rowMap, colMap;  
        int answer = 0; 
        for(int i = 0; i < grid.size(); i++){
            string row = ""; 
            for(int j = 0; j < grid[0].size(); j++){
                row  += to_string(grid[i][j]) + '!'; 
            }
            //cout << row << endl; 
            rowMap[row]++; 
        }

        for(int j = 0; j < grid[0].size(); j++){
            string col = ""; 
            for(int i = 0; i < grid.size(); i++){
                col += to_string(grid[i][j]) + '!'; 
            }
            //cout << col << endl; 
            answer += rowMap[col]; 
        }
        return answer; 
    }
};