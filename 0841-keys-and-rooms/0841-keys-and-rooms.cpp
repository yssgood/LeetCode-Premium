class Solution {
public:

    bool dfs(int start, vector<vector<int>>& rooms, vector<bool>& visited, int& roomcount){
        roomcount++; 
        if (roomcount == rooms.size()){
            return true;
        }
        
        visited[start] = true;
        
        
        for (int i = 0; i < rooms[start].size(); i++){
            if (!visited[rooms[start][i]]){
                if (dfs(rooms[start][i],rooms,visited,roomcount)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int roomcount = 0;
        int start = 0;
        int n = rooms.size();
        vector<bool> visited(n);
        visited[0] = true;
        
        return dfs(start,rooms,visited,roomcount);
        
    }
};