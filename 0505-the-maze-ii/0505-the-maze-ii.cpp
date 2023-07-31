// class Solution {
//     struct Ball{
//         int x, y, dist; 
//     };
//     vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; 
// public:
//     int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
//         int visited[maze.size()][maze[0].size()]; 
//         memset(visited,10000,sizeof(visited)); 
//         queue<Ball> q; 
//         q.push({start[0],start[1],0}); 
//         visited[start[0]][start[1]] = 0; 

//         while(!q.empty()){
//             int size = q.size();
//             for(int i = 0; i < size; i++){
//                 Ball ball = q.front();
//                 q.pop(); 
//                 int x = ball.x, y = ball.y, dist = ball.dist; 

//                 if(x == destination[0] && y == destination[1]) return dist; 

//                 for(pair<int,int>& p : dir){
//                     int nX = x, nY = y; 
//                     int nDist = 0; 
//                     while(nX >= 0 && nY >= 0 && nX < maze.size() && nY < maze[0].size() && maze[nX][nY] == 0){
//                         nX += p.first; 
//                         nY += p.second; 
//                         nDist++; 
//                     }

                    

//                     nX -= p.first; 
//                     nY -= p.second; 
//                     nDist--; 

//                     //cout << nX << ' ' << nY << ' ' << nDist << endl; 
                    
//                     if(visited[nX][nY] > nDist + dist){
//                         q.push({nX, nY, nDist + dist}); 
//                         visited[nX][nY] = nDist + dist; 
//                     }

//                 }

//             }
//         }

//         return visited[destination[0]][destination[1]] == 269488144 ? -1 : visited[destination[0]][destination[1]]; 
//     }
// };

class Solution {
    struct Ball{
        int x, y, dist; 
    };
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int visited[maze.size()][maze[0].size()]; 
        memset(visited,10000,sizeof(visited)); 
        queue<Ball> q; 
        q.push({start[0],start[1],0});
        visited[start[0]][start[1]] = 0; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Ball first = q.front(); 
                q.pop(); 
                int x = first.x, y = first.y, dist = first.dist; 
                for(int j = 0; j < dir.size(); j++){
                    int nX = x, nY = y, curr_dist = 0; 
                    while(nX >= 0 && nX < maze.size() && nY >= 0 && nY < maze[0].size() && maze[nX][nY] != 1){
                        ++curr_dist; 
                        nX += dir[j].first; 
                        nY += dir[j].second; 
                    }
                    nX -= dir[j].first; 
                    nY -= dir[j].second; 
                    curr_dist--; 
                    //cout << nX << ' ' << nY << ' ' << curr_dist << endl; 

                    if(visited[nX][nY] > dist + curr_dist){
                        visited[nX][nY] = dist + curr_dist; 
                        q.push({nX,nY,dist + curr_dist}); 
                    }
                }
            }
        }
        return visited[destination[0]][destination[1]] == 269488144 ? -1 : visited[destination[0]][destination[1]]; 
    }
};