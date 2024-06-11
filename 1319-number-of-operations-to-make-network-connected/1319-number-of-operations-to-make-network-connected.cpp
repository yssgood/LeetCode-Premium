class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int& edge){
        visited[node] = true; 
        for(int next : adj[node]){
            if(!visited[next]){
                edge++; 
                dfs(adj,visited,next,edge); 
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - (int)connections.size() > 1) return -1; 
        vector<vector<int>> adj(n); 
        for(vector<int>& v : connections){
            int from =  v[0], to = v[1]; 
            adj[from].push_back(to);
            adj[to].push_back(from); 
        }

        vector<bool> visited(n,false); 
        int edge = 0; 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj,visited,i,edge); 
            }
        }
        

        return (n-1) - edge; 
    }
};