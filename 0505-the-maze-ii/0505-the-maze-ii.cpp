class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<vector<int>> q; 
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(),INT_MAX)); 
        q.push({start[0],start[1],0}); 
        visited[start[0]][start[1]] = 0; 
        int answer = INT_MAX; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 

                if(x == destination[0] && y == destination[1]){
                    answer = min(answer, dist); 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 
                    int nDist = dist + 1; 

                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size()) continue; 
                    
                    while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] != 1){
                        nX += p.first; 
                        nY += p.second; 
                        nDist++;
                    }
                    
                    nX -= p.first; 
                    nY -= p.second; 
                    nDist--; 

                    if(nX == destination[0] && nY == destination[1]){
                        answer = min(answer, nDist); 
                    }

                    if(visited[nX][nY] > nDist){
                        visited[nX][nY] = nDist;  
                        q.push({nX,nY,nDist}); 
                    }
                }
            }
        }

        return answer == INT_MAX ? -1 : answer; 
    }
};