class Solution {
public:
    int visited[2001]; 
    stack<int> nodeStack; 
    bool dfs(vector<vector<int>>& adj, int node){
        if(visited[node] == 1) return false; 
        if(visited[node] == 2) return true; //중복으로 탐색하는 것을 방지 
        visited[node] = 1; 

        for(int next : adj[node]){
            if(!dfs(adj,next)) return false; 
        }

        visited[node] = 2; 
        nodeStack.push(node); 
        return true; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1) return {0}; 
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& p : prerequisites){
            int to = p[0], from = p[1]; 
            adj[from].push_back(to); 
        }

        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && !dfs(adj,i)) return {}; 
        }

        vector<int> res; 

        while(!nodeStack.empty()){
            res.push_back(nodeStack.top()); 
            nodeStack.pop(); 
        }

        return res; 
    }
};