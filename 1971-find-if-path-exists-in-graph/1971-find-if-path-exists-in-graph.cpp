class Solution {
public:
    
    bool dfs(int n, vector<vector<int>>& ourVec, vector<bool>& visited, int source, int destination){
        if (source == destination){
            return true;
        }
        
        visited[source] = true; //current node as true  
                
        for (int i = 0; i < ourVec[source].size(); i++){
            if (!visited[ourVec[source][i]]){
                if (dfs(n, ourVec, visited, ourVec[source][i],destination) == true){
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    //dfs(1) 
    //dfs(0) 
    //dfs(1) 
    //... 
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> ourVec(n); 
        for (int i = 0; i < edges.size(); i++){
            ourVec[edges[i][0]].push_back(edges[i][1]);
            ourVec[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n);
        for (int i = 0; i < n; i++){
            visited[i] = false;
        }
        
        return dfs(n,ourVec, visited, source, destination);    
    }
};


/*\


// ourVec = [0] -> {1,2} 


vector<int> visited 

[0] = false 
[1] = false 
[2] = false 

!visited[source] 
visited[source] 

ourVec 

index of your ourVec will serve as information for that node part 
index 0 -> {1} 
index 1 -> {0} 
index 2 



0 - 1 

        // ourVec = [0:{1,2}]
        // ourVec = [0] -> {1,2} 
        
        
        //your dfs should be able to travel all nodes without specifying path 
        //dfs(0) 
        //
        
        //dfs(1) 
        //dfs(2) 


*/ 