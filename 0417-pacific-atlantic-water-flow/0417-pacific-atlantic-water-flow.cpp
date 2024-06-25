class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true; 

        for(pair<int,int>& p : dir){
            int nX = i + p.first; 
            int nY = j + p.second; 
            if(nX >= 0 && nY >= 0 && nX < heights.size() && nY < heights[0].size()&& heights[nX][nY] >= heights[i][j] && !visited[nX][nY]){
                dfs(heights,visited,nX,nY); 
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        vector<vector<bool>> p_visited(heights.size(), vector<bool>(heights[0].size(),false)); 
        vector<vector<bool>> a_visited(heights.size(), vector<bool>(heights[0].size(),false)); 
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i == 0 || j == 0){
                    dfs(heights,p_visited,i,j); 
                }

                if(i == heights.size()-1 || j == heights[0].size()-1){
                    dfs(heights,a_visited,i,j); 
                }
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(p_visited[i][j] && a_visited[i][j]){
                    answer.push_back({i,j}); 
                }
            }
        }


        return answer; 

    }
};