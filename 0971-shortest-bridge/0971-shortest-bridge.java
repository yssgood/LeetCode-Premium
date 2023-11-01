class Solution {
    int[][] dir = {{0,1},{0,-1},{-1,0},{1,0}}; 
    class Node{
        int x, y, dist; 
        Node(int x, int y, int dist){
            this.x = x;
            this.y = y; 
            this.dist = dist; 
        }
    }
    public void dfs(int i, int j, int[][] grid){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != 1) return; 
        grid[i][j] = 2; 
        dfs(i+1,j,grid); 
        dfs(i-1,j,grid); 
        dfs(i,j+1,grid);
        dfs(i,j-1,grid); 
    }
    public int bfs(int i, int j, Queue<Node> q, int[][] grid){
        boolean[][] visited = new boolean[grid.length][grid[0].length]; 
        visited[i][j] = true; 
        
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int k = 0; k < size; k++){
                Node first = q.poll(); 
                int x = first.x, y = first.y, dist = first.dist; 
                
                if(grid[x][y] == 2) return dist - 1; 
                
                for(int[] d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 
                    
                    if(nX < 0 || nY < 0 || nX >= grid.length || nY >= grid[0].length || visited[nX][nY] || grid[nX][nY] == 1) continue; 
                    visited[nX][nY] = true; 
                    q.add(new Node(nX,nY,dist+1)); 
                }
            }
        }
        return Integer.MAX_VALUE; 
    }
    public int shortestBridge(int[][] grid) {
        
        boolean flag = false; 
        int answer = Integer.MAX_VALUE; 
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(!flag && grid[i][j] == 1){
                    dfs(i,j,grid); 
                    flag = true; 
                }
            }
            if(flag) break; 
        }
        
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    Queue<Node> q = new LinkedList<>(); 
                    q.add(new Node(i,j,0)); 
                    answer = Math.min(answer,bfs(i,j,q,grid)); 
                }
            }
        }
        return answer; 
    }
}