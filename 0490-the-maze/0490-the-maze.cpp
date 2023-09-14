class Solution {
    struct Ball{
        int x, y; 
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false)); 
        queue<Ball> q; 
        q.push({start[0],start[1]}); 
        visited[start[0]][start[1]] = true; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Ball first = q.front(); 
                q.pop(); 

                int x = first.x, y = first.y; 
                if(x == destination[0] && y == destination[1]) return true; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] == 0){
                        nX += p.first;
                        nY += p.second; 
                    }

                    nX -= p.first;
                    nY -= p.second; 

                    if(!visited[nX][nY]){
                        visited[nX][nY] = true; 
                        q.push({nX,nY}); 
                    }
                }
            }
        }
        return false; 
    }
};