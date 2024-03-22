class Solution {

public:
    bool dfs(vector<vector<int>>& adj, vector<int>& findCycle, vector<int>& visited, int source, int destination){

        if(adj[source].empty()){
            return destination == source; 
        }

        for(int& nextNode : adj[source]){
            
            if(visited[source]) continue; 

            if(findCycle[nextNode]) return false; 

            findCycle[nextNode] = true; 
            if(dfs(adj, findCycle, visited, nextNode, destination) == false) return false; 
            findCycle[nextNode] = false;  


        }
        visited[source] = true; 
        return true; 
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            adj[from].push_back(to); 
        }

        vector<int> findCycle(n,0); 
        vector<int> visited(n,0); 

        return dfs(adj,findCycle,visited,source,destination); 
    }
};