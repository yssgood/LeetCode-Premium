class Solution {
public:
    bool visited[201]; 
    void dfs(vector<vector<int>>& isConnected, int node){
        visited[node] = true; 
        for(int i = 0; i < isConnected[node].size(); i++){
            if(i == node) continue; 
            int next = isConnected[node][i];
            if(!visited[i] && next == 1){
                dfs(isConnected,i); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0; 
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected,i); 
                count++; 
            }
        }
        return count; 
    }
};