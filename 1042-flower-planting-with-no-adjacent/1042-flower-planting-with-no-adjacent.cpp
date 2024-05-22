class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& answer, int& flower, int node){
        
        for(int next : adj[node]){
            if(!visited[next]){
                if(flower + 1 > 4) flower = 0; 
                answer[next-1] = ++flower;
                visited[next] = true; 
                dfs(adj,visited, answer, flower, next); 
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> answer(n,0); 
        vector<bool> visited(n+1, false); 
        vector<vector<int>> adj(n + 1);
        
        for(vector<int>& v : paths){
            int from = v[0], to = v[1]; 
            
            adj[from].push_back(to); 
            adj[to].push_back(from); 
        }
        
        int flower = 1; 
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = true; 
                flower = 1; 
                answer[i-1] = flower; 
                dfs(adj, visited, answer, flower, i); 
            }
        }
        
        return answer; 
    }
};