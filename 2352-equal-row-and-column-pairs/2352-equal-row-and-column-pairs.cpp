class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int answer = 0; 
        map<string,int> rowMap; 
        for(int i = 0; i < grid.size(); i++){
            string tmp = ""; 
            for(int j = 0; j < grid[0].size(); j++){
                tmp += to_string(grid[i][j]); 
            }
            rowMap[tmp]++; 
        }

        for(int i = 0; i < grid.size(); i++){
            string tmp = ""; 
            for(int j = 0; j < grid[0].size(); j++){
                tmp += to_string(grid[j][i]); 
            }
            
            if(rowMap.count(tmp)) answer += rowMap[tmp]; 
        }

        return answer; 

        
    }
};