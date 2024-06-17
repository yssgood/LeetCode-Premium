class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n+1); 
        vector<int> indegree(n+1); 
        for(vector<int>& v : relations){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
            indegree[to]++; 
        }

        queue<int> q; 
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i); 
            }
        }

        int time = 0; 
        int nodes = 0; 
        while(!q.empty()){
            int size = q.size();
            time++; 
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop(); 
                nodes++; 
                for(int next : adj[node]){
                    indegree[next]--; 
                    if(indegree[next] == 0){
                        q.push(next); 
                    }
                }
            } 
        }
        //cout << nodes << ' ' << time; 
        return nodes == n ? time : -1; 
    }
};