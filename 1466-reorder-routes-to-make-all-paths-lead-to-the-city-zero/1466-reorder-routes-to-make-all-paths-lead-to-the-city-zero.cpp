class Solution {
public:
    struct Node{
        int to;
        bool out, in; 
    };
    void dfs(vector<vector<Node>>& adj, vector<int>& visited, int node, int& answer){
        visited[node] = true; 
        for(Node& next : adj[node]){
            if(!visited[next.to]){
                if(next.out == true) answer++;  
                dfs(adj,visited,next.to,answer); 
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<Node>> adj(n); 
        vector<int> visited(n,false); 
        for(vector<int>& v : connections){
            int from = v[0], to =v[1]; 

            adj[from].push_back({to, true, false});
            adj[to].push_back({from, false, true}); 
        }

        int answer = 0; 

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj,visited,i,answer); 
            }
        }

        return answer; 
    }
};