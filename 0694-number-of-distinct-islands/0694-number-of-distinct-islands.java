class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    char[] letter = {'r','l','u','d'}; 
    public int numDistinctIslands(int[][] grid) {
        int n = grid.length;  
        int m = grid[0].length; 
        Set<String> answer = new HashSet<>(); 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    String curr = "s"; 
                    String res = dfs(grid,i,j,curr);
                    System.out.println(res); 
                    answer.add(res); 
                }
            }
        }
        return answer.size(); 
    }

    public String dfs(int[][] grid, int i, int j, String curr){
        if(i >= grid.length || j >= grid[0].length || i < 0 || j < 0 || grid[i][j] != 1) return ""; 

        grid[i][j] = 0; 


        for(int k = 0; k < 4; k++){
            int nX = i + dir[k][0]; 
            int nY = j + dir[k][1]; 

            char c = letter[k]; 

            if(nX < grid.length || nY < grid[0].length || nX >= 0 || nY >= 0 || grid[nX][nY] == 1){
                curr += c; 
                curr += dfs(grid,nX,nY,""); 
                //curr += "?"; 
            }

            //curr += dfs(grid,nX,nY,curr); 
        }


        return curr; 
    }
}