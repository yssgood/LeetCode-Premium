class Solution {
public:
    int visited[10001]; 
    bool dfs(vector<vector<int>>& adj, int source, int destination){
        if(visited[source] == 2) return true; 
        if(visited[source] == 1) return false; 
        visited[source] = 1; 
        for(int next : adj[source]){
            if(!dfs(adj,next,destination)) return false; 
        }
        visited[source] = 2; 
        if(adj[source].empty() && source != destination) return false; 
        return true; 
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
        }

        bool res = dfs(adj,source,destination); 
        return res; 
    }
};