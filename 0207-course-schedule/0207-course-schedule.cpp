class Solution {
public:
    int visited[2001]; 
    bool dfs(vector<vector<int>>& adj, int node){
        if(visited[node] == 1) return false; 
        if(visited[node] == 2) return true; 
        visited[node] = 1; 
        for(int next : adj[node]){
            if(!dfs(adj, next)) return false; 
        }
        visited[node] = 2; 
        return true; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& v : prerequisites){
            int to = v[0], from = v[1]; 
            adj[from].push_back(to); 
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(!dfs(adj,i)) return false; 
            }
        }
        return true; 
    }
};


//3 <- 1 <- 4 
// 2 <- 4 
// 