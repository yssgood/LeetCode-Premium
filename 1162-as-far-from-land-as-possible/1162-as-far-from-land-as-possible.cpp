class Solution {
public:
    struct Node{
        int x, y, dist; 
    };
    bool visited[101][101]; 
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};  
    int maxDistance(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited)); 
        int answer = -1; 
        queue<Node> q; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
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
                    answer = max(answer, dist + 1); 
                    q.push({nX, nY, dist +1}); 
                }
            }
        }

        return answer; 
    }
};