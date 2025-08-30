class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int getFood(vector<vector<char>>& grid) {
        queue<vector<int>> q; 
        int n = grid.size(), m = grid[0].size(); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    grid[i][j] = 'X'; 
                    q.push({i,j,0});
                    break; 
                }
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 
                int x = curr[0], y = curr[1], dist = curr[2];; 
                // if(grid[x][y] == '#'){
                //     return dist; 
                // }

                //grid[x][y] = 'X'; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 
                    if(nX < 0 || nY < 0 || nX >= n || nY >= m || grid[nX][nY] == 'X') continue; 
                    if(grid[nX][nY] == '#'){
                        return dist + 1; 
                    }
                    grid[nX][nY] = 'X';
                    q.push({nX,nY,dist+1}); 
                }
            }
        }

        return -1; 
    }
};