class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; 
        int freshOrange = 0; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j}); 
                }
                if(grid[i][j] == 1){
                    freshOrange++; 
                }
            }
        }

        if(!freshOrange) return 0; 

        int time = -1; 
        
        while(!q.empty()){
            int size = q.size(); 
            time++; 
            for(int i = 0; i < size; i++){
                pair<int,int> curr = q.front(); 
                q.pop(); 
                int x = curr.first, y = curr.second; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first; 
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || grid[nX][nY] != 1) continue; 

                    grid[nX][nY] = 2; 
                    q.push({nX,nY}); 
                    freshOrange--; 
                }
            }
        }


        return freshOrange == 0 ? time : -1; 
    }
};