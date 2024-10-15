class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q; 
        q.push({entrance[0], entrance[1], 0}); 
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> v = q.front(); 
                q.pop(); 

                int x = v[0], y = v[1], dist = v[2]; 
                maze[x][y] = '+'; 
                if(dist > 0 && (x == maze.size()-1 || x == 0) || dist > 0 && (y == maze[0].size()-1 || y == 0)){
                    return dist; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 
                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size() || maze[nX][nY] == '+') continue; 

                    maze[nX][nY] = '+'; 
                    q.push({nX,nY,dist+1}); 
                }
            }
        }
        return -1; 
    }
};