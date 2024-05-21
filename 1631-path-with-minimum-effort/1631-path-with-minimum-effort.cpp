class Solution {
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int visited[101][101]; 
struct Node{
    int x, y,dist;
};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        memset(visited,9876543,sizeof(visited)); 
        queue<Node> q; 
        q.push({0,0,INT_MIN}); 
        visited[0][0] = 0; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Node node = q.front(); 
                q.pop();
                int x = node.x, y = node.y, dist = node.dist; 
                
                
                
                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second;
                    
                    if(nX < 0 || nX >= heights.size() || nY < 0 || nY >= heights[0].size()) continue; 
                    
                    int nDist = max(dist,abs(heights[x][y] - heights[nX][nY])); 
                    if(visited[nX][nY] > nDist){
                        visited[nX][nY] = nDist; 
                        q.push({nX,nY,nDist}); 
                    }
                }
            }
        }

        return visited[heights.size()-1][heights[0].size()-1]; 
    }
};