class Solution {
public:
    int visited[2001]; 
    stack<int> stack; 
    bool dfs(vector<vector<int>>& adj, int node){
        if(visited[node] == 1) return false; //not yet completed  
        if(visited[node] == 2) return true; //completed
        visited[node] = 1; //in progress 
        for(int next : adj[node]){
            if(!dfs(adj,next)) return false; 
        }

        visited[node] = 2; //complete
        stack.push(node); 
        return true; 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer; 
        // if(prerequisites.empty()){
        //     for(int i = 0; i < numCourses; i++){
        //         answer.push_back(i);         
        //     }
        // }
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& v : prerequisites){
            int to = v[0], from = v[1]; 
            adj[from].push_back(to); 
        }
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0 && !dfs(adj,i)){
                return {}; 
            }
        }

        while(!stack.empty()){
            answer.push_back(stack.top());  
            stack.pop(); 
        }
        return answer; 
    }
};