class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int destination){
        if(node == destination) return true; 
        visited[node] = true; 
        for(int next : adj[node]){
            if(!visited[next]){
                if(dfs(adj,visited,next,destination)) return true; 
            }
        }
        return false; 
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); 
        vector<bool> visited(n,false); 
        for(vector<int>& e : edges){
            int from = e[0], to = e[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }
        
        return dfs(adj,visited,source,destination); 
    }
};