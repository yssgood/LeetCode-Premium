class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1; 
        queue<vector<int>> q; 
        q.push({0,0,0}); 
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),INT_MAX)); 
        visited[0][0] = 0; 

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front();
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 
                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 
                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || grid[nX][nY] != 0) continue; 

                    if(visited[nX][nY] > dist + 1){
                        visited[nX][nY] = dist + 1; 
                        q.push({nX, nY, dist + 1});
                    }
                }
            }
        }
        return visited[grid.size()-1][grid[0].size()-1] == INT_MAX ? -1 : visited[grid.size()-1][grid[0].size()-1] + 1; 
    }
};