class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    char[] dirChar = {'R','L','D','U'}; 
    Set<String> set = new HashSet<>(); 
    public int numDistinctIslands(int[][] grid) {
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    StringBuilder sb = new StringBuilder(); 
                    sb.append("C"); 
                    dfs(grid,i,j,sb); 
                    set.add(sb.toString());
                }
            }
        }

        return set.size(); 
    }

    void dfs(int[][] grid, int i, int j, StringBuilder sb){
        grid[i][j] = 0; 
        for(int k = 0; k < 4; k++){
            int nX = i + dir[k][0]; 
            int nY = j + dir[k][1]; 
            if(nX >= 0 && nY >= 0 && nX < grid.length && nY < grid[0].length && grid[nX][nY] == 1){
                sb.append(dirChar[k]); 
                dfs(grid,nX,nY,sb); 
            }
        }
    }
}