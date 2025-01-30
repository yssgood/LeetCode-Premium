class Solution {
    void dfs(boolean[] visited, List<List<Integer>> adj, int node){
        visited[node] = true; 
        for(int n : adj.get(node)){
            if(!visited[n]){
                dfs(visited,adj,n); 
            }
        }
    }
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()]; 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < rooms.size(); i++){
            adj.add(new ArrayList<>()); 
        }

        for(int i = 0; i < rooms.size(); i++){
            adj.set(i,rooms.get(i)); 
        }

        dfs(visited,adj,0); 

        for(int i = 0; i < rooms.size(); i++){
            if(!visited[i]) return false; 
        }

        return true; 
    }
}