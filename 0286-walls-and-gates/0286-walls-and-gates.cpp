class Solution {
    struct Gates{
        int x, y, dist; 
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<Gates> q; 
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i,j,0}); 
                }
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Gates first = q.front(); 
                q.pop(); 

                int x = first.x, y = first.y, dist = first.dist; 

                for(pair<int,int> p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= rooms.size() || nY >= rooms[0].size() || rooms[nX][nY] == -1) continue; 

                    if(rooms[nX][nY] > dist + 1){
                        rooms[nX][nY] = dist + 1; 
                        q.push({nX,nY,dist+1}); 
                    }
                }
            }
        }
    }
};