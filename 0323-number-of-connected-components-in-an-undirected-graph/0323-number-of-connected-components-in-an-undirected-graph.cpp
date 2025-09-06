class Solution {
public:

    void dfs(int start, vector<vector<int>>& ourVec, vector<bool>& visited){
        
        visited[start] = true;
        for (int i = 0; i < ourVec[start].size(); i++){
            if (!visited[ourVec[start][i]]){
                dfs(ourVec[start][i],ourVec,visited);
            }
        }
        
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ourVec(n);
        for (int i = 0; i < edges.size(); i++){
            ourVec[edges[i][0]].push_back(edges[i][1]);
            ourVec[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n);
        
        int count = 0;
        
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                count++;
                dfs(i,ourVec,visited);
            }
        }
        
        return count;
        
    }
};

        //source node can be any nodes 
        //0 .. n 
        
        //0 -> dfs(0) -> we will be able to find connected components from 0 
        //1 -> markes as visited from our array (visited[1] = true) 
        