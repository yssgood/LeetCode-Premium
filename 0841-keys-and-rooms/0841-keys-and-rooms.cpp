class Solution {
public:
    bool visited[1001]; 
    void dfs(vector<vector<int>>& rooms, int curr, int& visitedCount){
        visited[curr] = true; 
        visitedCount++; 
        for(int next : rooms[curr]){
            if(!visited[next]){
                dfs(rooms, next, visitedCount); 
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited[0] = true; 
        int visitedCount = 0; 
        dfs(rooms,0,visitedCount);
        return visitedCount < rooms.size() ? false : true;  

    }
};