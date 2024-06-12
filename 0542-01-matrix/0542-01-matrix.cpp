class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(),0)); 
        queue<vector<int>> q; 
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0}); 
                }
                if(mat[i][j] == 1){
                    answer[i][j] = INT_MAX; 
                }
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front();
                q.pop(); 

                int x = curr[0], y = curr[1], dist = curr[2]; 
                
                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= mat.size() || nY >= mat[0].size()) continue; 

                    if(answer[nX][nY] > dist + 1){
                        answer[nX][nY] = dist + 1; 
                        q.push({nX,nY,dist+1}); 
                    }
                }
            }
        }
        return answer; 
    }
};