class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0  || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1) return; 

        grid[i][j] = 1; 

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1); 
    }
    int closedIsland(vector<vector<int>>& grid) {
        //1. grid 밖에 있는 0을 찾는다. 
        //-> i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size() -1 -> if (grid[i][y] == 0) dfs() 

        //2. grid 를 다시 탐색한다 
        //if grid[x][y] = 0 -> dfs() 
        //answer++ 

        //사전 작업 (1) 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1){
                    if(grid[i][j] == 0){
                        dfs(grid,i,j); 
                    }
                } 
            }
        }

        int answer = 0; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    answer++;
                    dfs(grid,i,j); 
                }
            }
        }

        return answer; 
    }
};