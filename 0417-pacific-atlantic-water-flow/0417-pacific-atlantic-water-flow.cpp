class Solution {
public:
    bool pacific[201][201]; 
    bool atlantic[201][201]; 
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(vector<vector<int>>& height, int i, int j, char ocean){

        if(ocean == 'P') pacific[i][j] = true; 
        if(ocean == 'A') atlantic[i][j] = true; 
        
        for(vector<int>& d : dir){
            int nX = i + d[0]; 
            int nY = j + d[1]; 

            if(nX >= 0 && nY >= 0 && nX < height.size() && nY < height[0].size() && height[nX][nY] >= height[i][j]){
                if(ocean == 'P' && !pacific[nX][nY]){
                    pacific[nX][nY] = true; 
                    dfs(height,nX,nY,ocean); 
                } else if(ocean == 'A' && !atlantic[nX][nY]){
                    atlantic[nX][nY] = true; 
                    dfs(height,nX,nY,ocean); 
                }

                
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i == 0 || j == 0){
                    dfs(heights, i, j, 'P'); 
                }

                if(i == heights.size()-1 || j == heights[0].size()-1){
                    dfs(heights, i, j, 'A'); 
                }
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j]){
                    answer.push_back({i,j}); 
                }
            }
        }

        return answer; 
    }
};