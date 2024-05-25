class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),INT_MAX));  
        queue<vector<int>> q; 
        if(grid[0][0] == 0){
            q.push({0,0,1}); 
            visited[0][0] = 1; 
        }
        

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> v = q.front();
                q.pop(); 

                int x = v[0], y = v[1], dist = v[2]; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || grid[nX][nY] == 1) continue; 

                    if(visited[nX][nY] > dist + 1){
                        visited[nX][nY] = dist + 1;
                        q.push({nX, nY, dist + 1}); 
                    }
                }
            }
        }

        return visited[grid.size()-1][grid[0].size()-1] == INT_MAX ? -1 : visited[grid.size()-1][grid[0].size()-1];
    }
};