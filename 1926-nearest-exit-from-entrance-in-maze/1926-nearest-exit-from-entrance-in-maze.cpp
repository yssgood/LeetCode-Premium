class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1}, {1,0}, {-1,0}}; 
    bool condition(int nX, int nY, vector<vector<char>>& maze){
        return (nX == 0 || nX == maze.size()-1 || nY == 0 || nY == maze[0].size()-1); 
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q; 
        q.push({entrance[0], entrance[1], 0}); 
        maze[entrance[0]][entrance[1]] = '+'; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size() || maze[nX][nY] == '+') continue; 

                    if(condition(nX,nY,maze)){
                        return dist + 1; 
                    }
                    
                    maze[nX][nY] = '+'; 
                    q.push({nX,nY,dist+1}); 
                    
                }
            }
        }

        return -1; 
    }
};