class Solution {
public:
    bool pVisited[201][201];
    bool aVisited[201][201]; 
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(int i, int j, char ocean, vector<vector<int>>& heights){
        int curr = heights[i][j]; 
        //cout << i << ' ' << j << ' ' << ocean << endl; 
        if(ocean == 'a') aVisited[i][j] = true; 
        if(ocean == 'p') pVisited[i][j] = true; 
        for(pair<int,int>& p : dir){
            int nX = i + p.first; 
            int nY = j + p.second; 
            
            if(nX >= 0 && nY >= 0 && nX < heights.size() && nY < heights[0].size() && heights[nX][nY] >= curr){
                if(ocean == 'a' && !aVisited[nX][nY]){
                    dfs(nX,nY,'a',heights); 
                }
                if(ocean == 'p' && !pVisited[nX][nY]){
                    dfs(nX,nY,'p',heights); 
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i == 0 || j == 0){
                    dfs(i,j,'p',heights); 
                }
                if(i == heights.size()-1 || j == heights[0].size()-1){
                    dfs(i,j,'a',heights); 
                }
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(aVisited[i][j] && pVisited[i][j]){
                    answer.push_back({i,j}); 
                }
            }
        }


        return answer; 
    }
};