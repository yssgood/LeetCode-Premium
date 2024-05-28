class Solution {
public:
    bool visited[100001]; 
    void dfs(vector<vector<int>>& adj, int node, int& answer){
        visited[node] = true; 
        for(int n : adj[node]){
            if(!visited[n]){
                answer--; 
                dfs(adj,n,answer); 
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size(); 
        if(n - size > 1) return -1; 
        memset(visited,false,sizeof(visited)); 
        
        vector<vector<int>> adj(n); 
        for(vector<int>& v : connections){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }

        int answer = n-1; 

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj,i,answer); 
            }
        }

        return answer; 
    }
};