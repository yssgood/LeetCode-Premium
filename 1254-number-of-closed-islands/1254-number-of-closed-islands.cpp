class Solution {
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}}; 

public:
    bool dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false; 
        if(grid[i][j] == 1) return true; 
        
        grid[i][j] = 1; 
        bool a = dfs(grid,i+1,j); 
        bool b = dfs(grid,i-1,j); 
        bool c = dfs(grid,i,j+1); 
        bool d = dfs(grid,i,j-1); 

        return a && b && c && d;  
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0 && dfs(grid,i,j)){
                    count++; 
                }
            }
        }
        return count; 
    }
};