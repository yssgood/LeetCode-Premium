class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool visited[101][101]; 
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        queue<pair<int,int>> q; 
        q.push({start[0],start[1]}); 
        visited[start[0]][start[1]] = true; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                pair<int,int> curr = q.front();
                q.pop(); 

                int x = curr.first, y = curr.second; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size() || maze[nX][nY] == 1) continue; 

                    while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] == 0){
                        nX += p.first; 
                        nY += p.second; 
                    }
                    
                    //cout << nX << ' ' << nY << endl; 

                    nX -= p.first;
                    nY -= p.second; 

                    

                    if(!visited[nX][nY]){
                        visited[nX][nY] = true; 
                        q.push({nX,nY}); 
                        if(nX == destination[0] && nY == destination[1]) return true; 
                    }
                }
            }
        }
        return false; 
    }
};