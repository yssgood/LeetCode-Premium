class Solution {
public:
    struct Node{
        int x,y, dist; 
    };

    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(), INT_MAX)); 
        queue<Node> q; 
        q.push({0,0,0}); 
        visited[0][0] = 0; 
        
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Node node = q.front();
                q.pop(); 

                int x = node.x, y = node.y, dist = node.dist; 

                if(x == heights.size()-1 && y == heights[0].size()-1){
                    int curr = visited[heights.size()-1][heights[0].size()-1];
                    visited[heights.size()-1][heights[0].size()-1] = min(curr,dist); 
                }

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= heights.size() || nY >= heights[0].size()) continue; 

                    int next_max = max(dist, abs(heights[nX][nY] - heights[x][y]));  

                    if(visited[nX][nY] > next_max){
                        visited[nX][nY] = next_max; 
                        q.push({nX,nY,next_max}); 
                    }
                }
            }
        }

        return visited[heights.size()-1][heights[0].size()-1]; 
    }
};