class Solution {
public:
    int numVisited = 0; 
    void dfs(vector<vector<int>>& rooms, int node, vector<bool>& visited){
        visited[node] = true; 
        numVisited++; 

        for(int n : rooms[node]){
            if(!visited[n]){
                dfs(rooms, n, visited); 
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false); 
        dfs(rooms, 0, visited); 
        return numVisited != rooms.size() ? false : true;  
    }
};