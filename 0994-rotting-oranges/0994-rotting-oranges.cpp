class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; 
        int allFresh = 0; 

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) allFresh++; 
                if(grid[i][j] == 2) q.push({i,j}); 
            }
        }

        if(q.empty()) return 0; 

        int distance = -1; 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                pair<int,int> curr = q.front();
                q.pop(); 


                int x = curr.first, y = curr.second; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= grid.size() || nY >= grid[0].size() || grid[nX][nY] != 1) continue; 

                    grid[nX][nY] = 2;
                    allFresh--; 
                    q.push({nX,nY}); 

                }
            }
            distance++; 
        }

        return allFresh > 0 ? -1 : distance; 
    }
};