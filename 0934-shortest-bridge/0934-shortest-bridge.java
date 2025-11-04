class Solution {
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        Queue<int[]> q = new LinkedList<>();
        
        // Step 1: Find first island, mark as 2, add all cells to queue
        boolean found = false;
        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < n && !found; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, q); // Pass queue to collect cells
                    found = true;
                }
            }
        }

        // Step 2: BFS from all cells of first island
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
        int steps = 0;
        
        while(!q.isEmpty()){
            int size = q.size(); // Process level by level
            
            for(int k = 0; k < size; k++){
                int[] curr = q.poll(); 
                int x = curr[0]; 
                int y = curr[1];
                
                for(int[] d : dir){
                    int nX = x + d[0];
                    int nY = y + d[1]; 
                    
                    if(nX >= 0 && nY >= 0 && nX < n && nY < n){
                        if(grid[nX][nY] == 1) return steps; // Found island 2!
                        
                        if(grid[nX][nY] == 0){ // Only visit water
                            grid[nX][nY] = 2; // Mark as visited
                            q.offer(new int[]{nX, nY}); 
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
    
    public void dfs(int[][] grid, int i, int j, Queue<int[]> q){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid.length || grid[i][j] != 1) return; 
        
        grid[i][j] = 2; // Mark as first island
        q.offer(new int[]{i, j}); // Add to queue for BFS
        
        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q); 
    }
}