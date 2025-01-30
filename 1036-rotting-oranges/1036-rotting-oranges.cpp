class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q; 
        int fresh = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2) q.push({i,j}); 
                if(grid[i][j] == 1) fresh++; 
            }
        }

        if(fresh == 0) return 0; 
        if(q.empty()) return -1; 

        int time = -1; 
        while(!q.empty()){
            int size = q.size(); 
            time++; 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int x = curr[0], y = curr[1]; 

                for(vector<int> d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 
                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || grid[nX][nY] != 1) continue; 

                    grid[nX][nY] = 2; 
                    fresh--; 
                    q.push({nX,nY}); 
                }
            }
        }

        return (fresh > 0) ? -1 : time; 
    }
};