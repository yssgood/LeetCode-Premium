class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true; 
        for(int next : adj[node]){
            if(!visited[next]){
                dfs(adj,visited,next); 
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int start = v[0], to = v[1]; 
            adj[start].push_back(to); 
            adj[to].push_back(start); 
        }

        vector<bool> visited(n); 
        int answer = 0; 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++; 
                dfs(adj,visited,i);
            }
        }
        return answer; 
    }
};