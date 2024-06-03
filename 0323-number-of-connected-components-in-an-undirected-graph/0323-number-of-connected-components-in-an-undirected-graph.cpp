class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true; 
        for(int nextNode : adj[node]){
            if(!visited[nextNode]){
                dfs(adj,visited,nextNode); 
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }

        vector<bool> visited(n,false); 
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