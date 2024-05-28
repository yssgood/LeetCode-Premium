class Solution {
public:
    queue<pair<int,int>> Q;
    int visited[303][303];
    int dy[4] = {1,0,-1,0};
    int dx[4] = {0,1,0,-1};
    int maxH, maxW;
    
    void bfs(int i, int j, vector<vector<char>>& grid){
        Q.push({i,j});
        int x, y, xx, yy;
        while(!Q.empty()){
            y = Q.front().first; x = Q.front().second; Q.pop();
            
            for(int i=0; i<4; i++){
                yy = y+dy[i]; xx = x+dx[i];
                if(yy<0||yy>=maxH||xx<0||xx>=maxW) continue;
                if(visited[yy][xx] == 1 || grid[yy][xx] == '0') continue;
                
                visited[yy][xx] = 1;
                Q.push({yy,xx});
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int answer =0;
        maxH = grid.size();
        maxW = grid[0].size();
        
        for(int i=0; i<303; i++){
            for(int j=0; j<303; j++){
                visited[i][j] = 0;
            }
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1' && visited[i][j]==0){
                    bfs(i,j, grid);
                    answer++;
                }        
            }
        }
        return answer;
    }
};