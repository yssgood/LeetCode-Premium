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
        //vector<vector<int>> adj(n) 
        //for() -> adj[from]->to, adj[to]->from 
        //vector<bool> visite(n)
        //for(int i = 0 -> n-1) dfs(); answer++ 
        //if(visited[i] == false) -> dfs(); answer++ 

        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }
        int answer = 0; 
        vector<bool> visited(n,false); 
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++; 
                dfs(adj,visited,i); 
            }
        }

        return answer; 
    }
};