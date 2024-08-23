class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool pacific[201][201]; 
    bool atlantic[201][201]; 
    void dfs(int i, int j, vector<vector<int>>& heights, char ocean){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return; 
        if(ocean == 'p' && pacific[i][j] || ocean == 'a' && atlantic[i][j]) return; 

        if(ocean == 'p') pacific[i][j] = true; 
        if(ocean == 'a') atlantic[i][j] = true; 

        for(pair<int,int>& p : dir){
            int nX = i + p.first; 
            int nY = j + p.second; 

            if(nX < 0 || nX >= heights.size() || nY < 0 || nY >= heights[0].size()) continue; 
            if(ocean == 'p' && pacific[nX][nY] || ocean == 'a' && atlantic[nX][nY]) continue; 

            if(heights[nX][nY] >= heights[i][j]){
                dfs(nX, nY, heights, ocean); 
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[i].size(); j++){
                if(i == 0 || j == 0){
                    dfs(i,j,heights,'p'); 
                }

                if(i == heights.size()-1 || j == heights[0].size()-1){
                    dfs(i,j,heights,'a'); 
                }
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[i].size(); j++){
                if(pacific[i][j] && atlantic[i][j]){
                    answer.push_back({i,j}); 
                }
            }
        }
        return answer; 
    }
};