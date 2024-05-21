class Solution {
public:
    int visited[201][201]; 
    vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 

    int dfs(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev >= matrix[i][j]){
            return 0; 
        }

        if(visited[i][j] != -1) return visited[i][j]; 

        int ret = 0; 
        for(pair<int,int>& p : dir){
            int nX = i + p.first; 
            int nY = j + p.second; 

            int tmp =  dfs(matrix,nX,nY, matrix[i][j]); 
            ret = max(ret, tmp); 
        }

        visited[i][j] = ret + 1; 

        return ret + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int answer = INT_MIN; 
        memset(visited,-1,sizeof(visited)); 
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                answer = max(answer, dfs(matrix,i,j,-1)); 
            }
        }

        return answer; 
    }
};