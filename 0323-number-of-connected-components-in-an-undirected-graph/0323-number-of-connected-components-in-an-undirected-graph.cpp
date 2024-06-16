class Solution {
public:
    bool visited[2001]; 
    void dfs(vector<vector<int>>& adj, int node){
        visited[node] = true;
        for(int next : adj[node]){
            if(!visited[next]){
                dfs(adj,next); 
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

        int answer = 0; 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++;
                dfs(adj,i); 
            }
        }
        return answer; 
    }
};