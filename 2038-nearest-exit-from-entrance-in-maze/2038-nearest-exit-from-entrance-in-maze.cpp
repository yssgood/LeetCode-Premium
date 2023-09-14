class Solution {
    struct Pos{
        int x, y, dist; 
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<Pos> q; 
        q.push({entrance[0],entrance[1],0}); 
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false)); 
        visited[entrance[0]][entrance[1]] = true; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Pos first = q.front();
                q.pop(); 
                int x = first.x, y = first.y, dist = first.dist;    

                //cout << x << ' ' << y << ' ' << dist << endl; 

                if(x == 0 || x == maze.size()-1 || y == 0 || y == maze[0].size()-1){
                    
                    if(x != entrance[0] || y != entrance[1]) return dist; 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second;  

                    if(nX < 0 || nY < 0 || nX >= maze.size() || nY >= maze[0].size() || maze[nX][nY] != '.' || visited[nX][nY]) continue; 

                    visited[nX][nY] = true; 
                    q.push({nX,nY,dist+1}); 

                }

            }
        }
        return -1; 
    }
};