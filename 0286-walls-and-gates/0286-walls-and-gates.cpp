class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q; 
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0) q.push({i,j,0}); 
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 

                for(vector<int>& d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 

                    if(nX < 0 || nY < 0 || nX >= rooms.size()|| nY >= rooms[0].size() || rooms[nX][nY] == -1) continue; 

                    if(rooms[nX][nY] > dist + 1){
                        rooms[nX][nY] = dist + 1; 
                        q.push({nX,nY,dist+1}); 
                    }
                }
            }
        }
    }
};