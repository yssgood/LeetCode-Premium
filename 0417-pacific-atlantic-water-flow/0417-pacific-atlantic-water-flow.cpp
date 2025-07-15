class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    bool pacific[201][201]; 
    bool atlantic[201][201]; 
    void dfs(vector<vector<int>>& heights, int m, int n, int i, int j, int prev, char letter){
        if(i < 0 || j < 0 || i >= m || j >= n || heights[i][j] < prev) return; 
        if(letter == 'P' && pacific[i][j] || letter == 'A' && atlantic[i][j]) return; 

        if(letter == 'P') pacific[i][j] = true; 
        if(letter == 'A') atlantic[i][j] = true; 

        dfs(heights,m,n,i+1,j,heights[i][j],letter); 
        dfs(heights,m,n,i-1,j,heights[i][j],letter); 
        dfs(heights,m,n,i,j+1,heights[i][j],letter); 
        dfs(heights,m,n,i,j-1,heights[i][j],letter); 
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        int m = heights.size(), n = heights[0].size(); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dfs(heights,m,n,i,j,heights[i][j],'P'); 
                }
                if(i == m-1 || j == n-1){
                    dfs(heights,m,n,i,j,heights[i][j],'A'); 
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    answer.push_back({i,j}); 
                }
            }
        }
        return answer; 
    }
};