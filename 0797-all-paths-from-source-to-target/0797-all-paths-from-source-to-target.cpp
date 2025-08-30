class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& answer, vector<int>& container, int node){
        container.push_back(node); 
        if(node == graph.size()-1){
            answer.push_back(container); 
            return; 
        }

        for(int next : graph[node]){
            dfs(graph,answer,container,next); 
            container.pop_back(); 
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer; 
        vector<int> container; 

        dfs(graph,answer,container,0); 
        return answer; 
    }
};