class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public int shortestBridge(int[][] grid) {
        int n = grid.length; 
        Queue<int[]> q = new LinkedList<>(); 
        boolean found = false; 
        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < n && !found; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,q); 
                    found = true; 
                }
            }
        }

        int answer = 0; 
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int[] curr = q.poll(); 
                int x = curr[0], y = curr[1], dist = curr[2]; 
                if(grid[x][y] == 1) return dist; 
                //grid[x][y] = 2; 
                System.out.println(x + " " + y); 

                for(int[] d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 
            

                    if(nX >= 0 && nY >= 0 && nX < n && nY < n && grid[nX][nY] != 2){
                        if(grid[nX][nY] == 1) return dist;
                        
                        grid[nX][nY] = 2; 
                        q.offer(new int[]{nX,nY,dist+1}); 
                    }
                }

            }
        }

        return -1; 
    }
    void dfs(int[][] grid, int i, int j, Queue<int[]> q){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != 1) return; 
        grid[i][j] = 2; 
        q.offer(new int[]{i,j,0}); 

        dfs(grid,i+1,j,q);
        dfs(grid,i-1,j,q);
        dfs(grid,i,j+1,q);
        dfs(grid,i,j-1,q); 
    }
}