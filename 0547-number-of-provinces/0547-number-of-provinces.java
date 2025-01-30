class Solution {
    public void dfs(int[][] isConnected, boolean[] visited, int node){
        visited[node] = true; 

        for(int i = 0; i < isConnected[node].length; i++){
            if(isConnected[node][i] == 1 && i != node && !visited[i]){
                dfs(isConnected,visited,i); 
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length; 
        boolean[] visited = new boolean[n];
        int answer = 0; 

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                answer++; 
                dfs(isConnected,visited,i); 
            }
        }

        return answer; 
    }
}