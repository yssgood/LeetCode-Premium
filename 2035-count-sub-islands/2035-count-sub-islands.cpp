class Solution {
    bool flag = true; 
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] != 1) return; 
        if(grid2[i][j] != grid1[i][j]) flag = false; 
        grid2[i][j] = 0; 
        
        dfs(grid1,grid2,i+1,j);
        dfs(grid1,grid2,i-1,j);
        dfs(grid1,grid2,i,j+1);
        dfs(grid1,grid2,i,j-1); 
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int answer = 0; 
        for(int i = 0; i < grid2.size(); i++){
            for(int j = 0;j < grid2[i].size(); j++){
                if(grid2[i][j] == 1){
                    flag = true; 
                    dfs(grid1,grid2,i,j); 
                    if(flag) answer++; 
                }
            }
        }
        return answer; 
    }
};