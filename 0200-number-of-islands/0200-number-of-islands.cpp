class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        vector<pair<int,int>> possiblemoves = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    count++;
                    queue<pair<int,int>> ourQ;
                    ourQ.push({i,j});
                    grid[i][j] = '0'; 
                    while (!ourQ.empty()){
                        pair<int,int> curr = ourQ.front();
                        ourQ.pop(); 
                        
                        int x = curr.first; 
                        int y = curr.second; 
                        
                        for (pair<int,int> possiblemove: possiblemoves){
                            int nX = x + possiblemove.first; 
                            int nY = y + possiblemove.second; 
                            
                            if (nX < grid.size() && nX >= 0 && nY < grid[x].size() && nY >= 0){
                                if (grid[nX][nY] == '1'){
                                    ourQ.push({nX,nY});
                                    grid[nX][nY] = '0';
                                }
                            }
                            
                        }
                    }
                    
                }
            }
        }
        return count;
    }
};