class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<vector<int>> q; 
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false)); 
        q.push({start[0],start[1]}); 
        visited[start[0]][start[1]] = true; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int x = curr[0], y = curr[1]; 

                for(vector<int>& d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 

                    while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] != 1){
                        nX += d[0]; 
                        nY += d[1]; 
                    }

                    nX -= d[0];
                    nY -= d[1]; 

                    if(nX == destination[0] && nY == destination[1]) return true; 

                    if(!visited[nX][nY]){
                        q.push({nX,nY}); 
                        visited[nX][nY] = true; 
                    }
                }
            }
        }
        return false; 
    }
};