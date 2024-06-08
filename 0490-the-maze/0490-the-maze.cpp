class Solution {
public:
    bool visited[101][101]; 
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int,int>> q; 
        q.push({start[0],start[1]}); 
        visited[start[0]][start[1]] = true; 

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int> node = q.front();
                q.pop(); 
                
                int x = node.first, y = node.second;

                if(x == destination[0] && y == destination[1]){
                    return true; 
                }

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
                        q.push({nX,nY}); 
                        visited[nX][nY] = true; 
                    }
                }
            }
        }
        return false; 
    }
};