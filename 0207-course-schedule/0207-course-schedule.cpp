class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inward(numCourses,0); 
        vector<bool> visited(numCourses,false); 
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& v : prerequisites){
            int to = v[0], from = v[1]; 
            inward[to]++; 
            adj[from].push_back(to); 
        }

        queue<int> q; 
        for(int i = 0; i < numCourses; i++){
            if(inward[i] == 0) q.push(i); 
        }

        if(q.empty()) return false; //there is a cycle 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int node = q.front(); 
                q.pop(); 
                visited[node] = true; 
                for(int next : adj[node]){
                    inward[next]--; 
                    if(inward[next] <= 0){
                        q.push(next); 
                    }
                }
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]) return false; 
        }

        return true; 

    }
};