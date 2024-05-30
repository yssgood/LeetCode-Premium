class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& server){
        grid[i][j] = 0; 
        server++; 

        for(int x = 0; x < grid.size(); x++){
            if(grid[x][j] == 1){
                dfs(grid,x,j,server); 
            }
        }

        for(int y = 0; y < grid[0].size(); y++){
            if(grid[i][y] == 1){
                dfs(grid,i,y,server); 
            }
        }
        return; 
    }
    int countServers(vector<vector<int>>& grid) {
        int answer = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int server = 0; 
                if(grid[i][j] == 1){
                    dfs(grid,i,j,server); 
                    if(server > 1) answer += server; 
                }
            }
        }
        return answer; 
    }
};

// [[1,0,0,1,0],
// [0,0,0,0,0],
// [0,0,0,1,0]]