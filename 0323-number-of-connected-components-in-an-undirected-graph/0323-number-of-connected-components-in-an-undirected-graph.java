class Solution {
    public void dfs(List<List<Integer>> adj, int index, boolean[] visited){
        visited[index] = true; 
        for(int next : adj.get(index)){
            if(visited[next] == false){
                dfs(adj,next,visited); 
            }
        }
    }
    public int countComponents(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int[] v : edges){
            int from = v[0], to = v[1]; 
            adj.get(from).add(to); 
            adj.get(to).add(from); 
        }

        boolean[] visited = new boolean[n]; 
        int count = 0; 
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs(adj,i,visited); 
                count++; 
            }
        }
        return count; 
    }
}