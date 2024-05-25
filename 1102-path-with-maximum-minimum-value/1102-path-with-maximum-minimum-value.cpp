class Solution {
    struct Node{
        int x, y, score; 
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int visited[101][101]; 
        memset(visited,0,sizeof(visited)); 
        queue<Node> q; 
        q.push({0,0,grid[0][0]}); 
        //visited[0][0] = INT_MAX; 

        while(!q.empty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                Node node = q.front(); 
                q.pop(); 

                int x = node.x, y = node.y, score = node.score; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size()) continue; 

                    int tmpScore = min(score, grid[nX][nY]); 

                    if(visited[nX][nY] < tmpScore){
                        visited[nX][nY] = tmpScore; 
                        q.push({nX,nY,tmpScore}); 
                    }
                }
            }
        }

        return visited[grid.size()-1][grid[0].size()-1]; 
    }
};
