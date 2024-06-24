class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int> rowMap, colMap; 
        for(int i = 0; i < grid.size(); i++){
            string Rowkey = ""; 
            //string Colkey = ""; 
            for(int j = 0; j < grid[0].size(); j++){
                //Rowkey += grid[i][j] + '0'; 
                //Colkey += grid[j][i] + '0'; 
                Rowkey += to_string(grid[i][j]); 
                //Colkey += to_string(grid[j][i]); 
            }
            rowMap[Rowkey]++; 
            //colMap[Colkey]++; 
        }

        int answer = 0;

        for(int i = 0; i < grid.size(); i++){
            string Colkey = ""; 
            for(int j = 0; j < grid[0].size(); j++){
                Colkey += to_string(grid[j][i]); 
            }
            if(rowMap.count(Colkey)){
                answer += rowMap[Colkey]; 
            }
        }

       
        return answer; 
    }
};


/*
[[13,13],
[13,13]]
*/