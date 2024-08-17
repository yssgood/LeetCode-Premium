class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node, int& answer){
        visited[node] = true; 
        for(int i = 0; i < isConnected[node].size(); i++){
            if(!visited[i] && isConnected[node][i] == 1){
                answer--; 
                dfs(isConnected, visited, i, answer); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = isConnected.size(); 
        vector<bool> visited(isConnected.size(),false); 
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                dfs(isConnected, visited, i, answer); 
            }
        }
        return answer; 
    }
};