class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(),INT_MAX)); 
        queue<vector<int>> q;
        q.push({0,0,0}); 
        visited[0][0] = 0; 
        
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front();
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 

                for(pair<int,int>& p : dir){
                    int nX =  x + p.first; 
                    int nY =  y + p.second; 
                    
                    if(nX < 0 || nY < 0 || nX >= heights.size() || nY >= heights[0].size()) continue; 

                    int nDist = max(dist, abs(heights[nX][nY] - heights[x][y])); 

                    if(visited[nX][nY] > nDist){
                        visited[nX][nY] = nDist; 
                        q.push({nX,nY,nDist}); 
                    }
                }
            }
        }

        return visited[visited.size()-1][visited[0].size()-1]; 
    }
};