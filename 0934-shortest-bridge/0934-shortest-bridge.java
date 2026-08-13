class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int N = 0; 
    public void dfs(int[][] grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid.length || grid[i][j] != 1) return; 
        grid[i][j] = 2; 
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1); 
    }
    public int shortestBridge(int[][] grid) {
        Deque<int[]> q = new ArrayDeque<>(); 
        boolean flag = false; 
        N = grid.length; 
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j); 
                    flag = true;
                    break; 
                }
            }
            if(flag) break; 
        }

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(grid[i][j] == 1){
                    q.add(new int[]{i,j}); 
                    grid[i][j] = -1; 
                }
            }
        }

        int answer = 0; 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int[] curr = q.poll(); 
                int x=  curr[0], y = curr[1]; 

                for(int[] d : dir){
                    int nX = x + d[0]; 
                    int nY = y + d[1]; 
                    if(nX >= 0 && nY >= 0 && nX < N && nY < N && grid[nX][nY] != -1){
                        if(grid[nX][nY] == 2) return answer; 
                        q.add(new int[]{nX,nY}); 
                        grid[nX][nY] = -1; 
                    }
                }
            }
            answer++; 
        }


        return -1;
    }
}