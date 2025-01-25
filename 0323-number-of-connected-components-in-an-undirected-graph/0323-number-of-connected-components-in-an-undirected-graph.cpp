class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited){
        visited[node] = true; 
        for(int next : adj[node]){
            if(!visited[next]){
                dfs(adj,next,visited); 
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        vector<bool> visited(n,false); 
        int answer = 0; 

        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++; 
                dfs(adj,i,visited); 
            }
        }

        return answer; 
    }
};