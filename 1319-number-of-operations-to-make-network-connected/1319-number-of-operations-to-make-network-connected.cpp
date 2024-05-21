class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true; 
        for(int& next : adj[node]){
            if(!visited[next])
            {
                dfs(adj,visited,next); 
            } 
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1; 
        vector<vector<int>> adj(n); 
        vector<bool> visited(n,false); 
        for(vector<int>& v : connections){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }
        int redundant = 0; 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                redundant++; 
                dfs(adj,visited,i); 
            }
        }


        return redundant - 1; 
    }
};