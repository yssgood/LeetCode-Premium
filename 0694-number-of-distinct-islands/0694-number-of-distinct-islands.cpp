class Solution {
public:
    void dfs(vector<vector<int>>& grid, string& tmp, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            //tmp.pop_back(); 
            return; 
        }

        grid[i][j] = 0; 
        dfs(grid,tmp+='d',i+1,j); 
        dfs(grid,tmp+='u',i-1,j);
        dfs(grid,tmp+='l',i,j-1);
        dfs(grid,tmp+='r',i,j+1); 
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> stringSet; 
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    string tmp = ""; 
                    dfs(grid,tmp,i,j); 
                    //sort(tmp.begin(), tmp.end()); 
                    stringSet.insert(tmp); 
                }
            }
        }
        // for(auto& it : stringSet){
        //     cout << it << ' '; 
        // }
        return stringSet.size(); 
    }
};

/*
[[0,1,1],
[1,0,1],
[1,1,0]]

*/ 