class Solution {
public:
    int visited[100001]; 
    bool dfs(vector<vector<int>>& adj, int source, int destination){
        if(visited[source] == 1) return false;  //found a cycle 
        if(visited[source] == 2) return true; 
        visited[source] = 1; 
        for(int next : adj[source]){
            if(!dfs(adj,next,destination)) return false; 
        }
        visited[source] = 2; 
        if(adj[source].size() == 0 && source != destination) return false; 
        return true; 
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
        }

        return dfs(adj,source,destination); 
    }
};