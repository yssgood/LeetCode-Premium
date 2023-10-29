class Solution {
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    struct Node{
        int x, y, currMax; 
    };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size(),INT_MAX)); 
        visited[0][0] = 0; 
        queue<Node> q; 
        q.push({0,0,-1}); 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Node first = q.front(); 
                q.pop(); 

                int x = first.x, y = first.y, currMax = first.currMax; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;  
                    int nY = y + p.second; 

                    if(nX < 0 || nX >= heights.size() || nY < 0 || nY >= heights[0].size()) continue;

                    int tmp = abs(heights[x][y] - heights[nX][nY]); 
                    int NcurrMax = max(currMax, tmp); 

                    if(visited[nX][nY] > NcurrMax){
                        visited[nX][nY] = NcurrMax;
                        q.push({nX,nY,NcurrMax}); 
                    }
                
                    

                }
            }

        }

        return visited[heights.size()-1][heights[0].size()-1]; 
    }
};

