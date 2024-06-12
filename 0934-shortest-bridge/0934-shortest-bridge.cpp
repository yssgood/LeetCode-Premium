class Solution {
public:
    bool visited[101][101]; 
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return; 

        grid[i][j]  = 2; 
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1); 
    }
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j);
                    flag = true;
                    break; 
                }
            }
            if(flag) break; 
        }

        queue<vector<int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i,j,0}); 
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front();
                q.pop(); 

                int x = curr[0], y = curr[1], flips = curr[2]; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size()) continue; 

                    //cout << nX << ' ' << nY << endl; 
                    if(grid[nX][nY] == 2){
                        return flips; 
                    } else if(grid[nX][nY] == 0){
                        grid[nX][nY] = 1; 
                        q.push({nX,nY,flips+1});  
                    }
                }
            }
        }

        return -1; 
        
    }
};