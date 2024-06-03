class Solution {
public:
    bool p_visited[201][201]; 
    bool a_visited[201][201]; 
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    void dfs(vector<vector<int>>& heights, int i, int j, char ocean){

        if(ocean == 'P'){
            p_visited[i][j] = true; 
        } else if(ocean == 'A'){
            a_visited[i][j] = true; 
        }

        for(pair<int,int>& d : dir){
            int nX = i + d.first; 
            int nY = j + d.second; 

            if(nX < 0 || nY < 0 || nX >= heights.size() || nY >= heights[0].size() || heights[nX][nY] < heights[i][j]) continue; 
            if(ocean == 'P' && p_visited[nX][nY]) continue; 
            if(ocean == 'A' && a_visited[nX][nY]) continue; 
            dfs(heights,nX, nY, ocean); 
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //vector<vector<int>> answer 
        //for() for() 
        //pacific == (i== 0) || (j == 0) 
        //atlantic == (i == n -1) || (j == heights[0].size() -1) 
        //visited[][] -> pacific 
        //visited[][] -> atlantic 

        vector<vector<int>> answer; 
        memset(p_visited,false,sizeof(p_visited)); 
        memset(a_visited,false,sizeof(a_visited)); 
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(i == 0 || j == 0){
                    dfs(heights, i, j, 'P'); 
                }
                if(i == heights.size()-1 || j == heights[0].size() -1){
                    dfs(heights, i, j, 'A'); 
                }
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(p_visited[i][j] && a_visited[i][j]){
                    answer.push_back({i,j}); 
                }
                //cout << p_visited[i][j] << ' '; 
            }
            //cout << endl; 
        }

        return answer; 
    }
};

