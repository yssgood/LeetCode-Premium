class Solution {
public: 
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visited){
        if(visited[node]){
            return visited[node] == 1; 
        }

        visited[node] = -1; 

        for(int n : graph[node]){
            if(!dfs(graph,n,visited)){
                return false; 
            }
        }

        visited[node] = 1; 

        return true; 
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),false); 
        vector<int> answer;  
        for(int i = 0; i < graph.size(); i++){
            if(dfs(graph,i,visited)){
                answer.push_back(i); 
            }
        }
        return answer; 
    }
};