class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return 0; 

        grid[i][j] = 0; 
        int cnt = 1; 
        cnt += dfs(grid,i+1,j);
        cnt += dfs(grid,i-1,j);
        cnt += dfs(grid,i,j+1);
        cnt += dfs(grid,i,j-1); 


        return cnt; 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer = 0; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    answer = max(answer,dfs(grid,i,j)); 
                }
            }
        }

        return answer; 
    }
};