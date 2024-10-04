class Solution {
    int[] visited = new int[100001]; 
    public boolean dfs(List<List<Integer>> adj, int source, int destination){
        if(visited[source] == 1) return false; //made cycle 
        if(visited[source] == 2) return true; 
        visited[source] = 1;  
        for(int next : adj.get(source)){
            if(!dfs(adj,next,destination)){
                return false; 
            }
        }
        visited[source] = 2; 
        if(adj.get(source).size() == 0 && source != destination) return false; 
        return true; 
    }
    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int[] e : edges){
            int from = e[0]; 
            int to = e[1]; 
            adj.get(from).add(to); 
        }


        return dfs(adj,source,destination); 
    }
}