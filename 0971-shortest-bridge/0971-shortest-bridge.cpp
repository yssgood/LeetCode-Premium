class Solution {
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool visited[101][101]; 
public: 
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return; 

        grid[i][j] = 2; 

        dfs(grid,i+1,j); 
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1); 
    }

public:
    int bfs(vector<vector<int>>& grid, int i, int j){
        queue<vector<int>> q; 
        q.push({i,j,0}); 
        //vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false)); 

        visited[i][j] = true; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> first = q.front();
                q.pop(); 

                int x = first[0], y = first[1], dist = first[2]; 
                if(grid[x][y] == 2){
                    return dist -1; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nX >= grid.size() || nY < 0 || nY >= grid[0].size() || grid[nX][nY] == 1 || visited[nX][nY]) continue; 

                    visited[nX][nY] = true; 
                    q.push({nX,nY,dist+1}); 
                }
            }
        }
        return INT_MAX; 
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = true; 
        int answer = INT_MAX; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j); 
                    flag = false; 
                    break; 
                }
            }
            if(!flag) break; 
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                memset(visited,false,sizeof(visited)); 
                if(grid[i][j] == 1){
                    answer = min(answer,bfs(grid,i,j)); 
                }
            }
        }


        return answer; 
    }
};