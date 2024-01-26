class Solution {

struct Node{
    int x, y, dist; 
};
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
public:
    int maxDistance(vector<vector<int>>& grid) {
        int answer = -1; 
        queue<Node> q; 
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i,j,0}); 
                    visited[i][j] = true; 
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node node = q.front();
                q.pop(); 
                int x = node.x, y = node.y, dist = node.dist; 
                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || visited[nX][nY]) continue; 

                    visited[nX][nY] = true;
                    q.push({nX,nY,dist+1}); 
                    answer = max(answer, dist+1); 
                }
            }
        }

        return answer; 
        
    }
};