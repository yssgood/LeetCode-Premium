class Solution {
public:
    bool pacific[201][201];  
    bool atlantic[201][201];  
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(int i, int j, int n, int m, char finder, vector<vector<int>>& heights){
        if(i < 0 || j < 0 || i >= n || j >= m) return; 
        
        if(finder == 'P') pacific[i][j] = true;  
        if(finder == 'A') atlantic[i][j] = true; 

        for(pair<int,int>& p : dir){
            int nX = i + p.first; 
            int nY = j + p.second; 

            if(i < 0 || j < 0 || i >= n || j >= m) continue; 
            if(nX < 0 || nY < 0 || nX >= n || nY >= m) continue; 

            if(finder == 'P' && !pacific[nX][nY] && heights[nX][nY] >= heights[i][j]) dfs(nX, nY, n, m, finder, heights); 
            if(finder == 'A' && !atlantic[nX][nY] && heights[nX][nY] >= heights[i][j]) dfs(nX, nY, n, m, finder, heights); 
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        int n = heights.size(); 
        int m = heights[0].size(); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    dfs(i,j,n,m,'P',heights); 
                }
                if(i == n-1 || j == m-1){
                    dfs(i,j,n,m,'A',heights);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //cout << pacific[i][j] << ' '; 
                if(pacific[i][j] && atlantic[i][j]) answer.push_back({i,j}); 
            }
            //cout << endl; 
        }
        return answer; 
    }
};