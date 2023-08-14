class Solution {


    void dfs(vector<vector<int>>& grid, int i, int j, string& way){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return; 

        grid[i][j] = 0; 

        dfs(grid,i+1,j,way+="D"); 
        dfs(grid,i-1,j,way+="U"); 
        dfs(grid,i,j+1,way+="R");
        dfs(grid,i,j-1,way+="L"); 

        
        way+="0"; 
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> container; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    string empty = ""; 
                    dfs(grid,i,j,empty);
                    //cout << empty << endl; 
                    container.insert(empty);
                }
            }
        }  
        return container.size(); 
    }
};