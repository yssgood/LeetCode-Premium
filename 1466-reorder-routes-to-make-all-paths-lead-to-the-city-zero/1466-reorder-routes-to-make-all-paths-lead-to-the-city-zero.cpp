class Solution {
public:
    bool visited[50001]; 
    void dfs(vector<vector<pair<int,bool>>>& adj, int node, int& answer){
        visited[node] = true; 
        for(pair<int,bool>& next : adj[node]){
            if(!visited[next.first]){
                answer += next.second == true ? 1 : 0; 
                dfs(adj,next.first,answer);  
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> adj(n); 
        for(vector<int>& v : connections){
            int from = v[0], to = v[1]; 
            adj[from].push_back({to,true}); 
            adj[to].push_back({from,false}); 
        }

        int answer = 0; 
        dfs(adj,0,answer);
        return answer; 
    }
};