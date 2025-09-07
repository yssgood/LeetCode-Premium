class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<pair<int,int>> possibleMoves = {{1,0},{-1,0},{0,-1},{0,1}};
        queue<vector<int>> ourQ;
        for (int i = 0; i < rooms.size(); i++){
            for (int j = 0; j < rooms[i].size(); j++){
                if (rooms[i][j] == 0){
                    ourQ.push({i,j,0});
                }
            }
        }
        
        while(!ourQ.empty()){
            int size = ourQ.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = ourQ.front();
                ourQ.pop();
                for (pair<int,int> possibleMove: possibleMoves){
                    int nX = possibleMove.first + curr[0];
                    int nY = possibleMove.second + curr[1];
                    if (nX < 0 || nX >= rooms.size() || nY < 0 || nY >= rooms[nX].size()){
                        continue; 
                    }
                    if (rooms[nX][nY] == -1){
                        continue;
                    }
                    if (curr[2] + 1 < rooms[nX][nY]){
                        rooms[nX][nY] = curr[2] + 1;
                        ourQ.push({nX,nY,rooms[nX][nY]});
                    }
                    
                }
                
            }
            
        }
        
    }
};


//add values to your queue 
//bfs from the gates 