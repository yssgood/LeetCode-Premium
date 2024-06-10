class Solution {
public:
    int visited[2001]; 
    bool dfs(vector<vector<int>>& adj, int node){
        if(visited[node] == 1) return false; //I'm still traversing and still visited this node 
        if(visited[node] == 2) return true; //finished traversing 


        visited[node] = 1; //still traversing 

        for(int next : adj[node]){
            if(!dfs(adj , next)) return false; //if I find cycle, just return 
        }

        visited[node] = 2;  

        return true; //end of traversal  
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& p : prerequisites){
            int to = p[0], from = p[1];  
            adj[from].push_back(to); 
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && !dfs(adj,i)) return false; 
        }
        return true; 
    }
};