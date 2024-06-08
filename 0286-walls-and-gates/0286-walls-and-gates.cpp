class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<vector<int>> q; 
        
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i,j,0}); 
                }
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> node = q.front();
                q.pop(); 

                int x = node[0], y = node[1], dist = node[2]; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= rooms.size() || nY >= rooms[0].size()) continue; 

                    if(rooms[nX][nY] > dist + 1){
                        rooms[nX][nY] = dist + 1; 
                        q.push({nX,nY,dist + 1}); 
                    }
                }
            }
        }
    }
};