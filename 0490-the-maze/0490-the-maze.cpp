class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool visited[101][101]; 
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int,int>> q; 
        q.push({start[0],start[1]}); 

        while(!q.empty()){
            int size = q.size();  

            for(int i = 0; i < size; i++){
                pair<int,int> curr = q.front(); 
                q.pop(); 

                int x = curr.first, y = curr.second; 

                if(x == destination[0]  && y == destination[1]){
                    return true; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size()) continue; 

                    while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] != 1){
                        nX += p.first; 
                        nY += p.second; 
                    }

                    nX -= p.first;
                    nY -= p.second; 

                    if(nX == destination[0] && nY == destination[1]){
                        return true; 
                    } 

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