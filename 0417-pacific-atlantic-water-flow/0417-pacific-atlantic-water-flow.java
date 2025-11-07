class Solution {
    boolean[][] pacific = new boolean[201][201]; 
    boolean[][] atlantic = new boolean[201][201];
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> answer = new ArrayList<>(); 
        int m = heights.length, n = heights[0].length; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dfs(heights,i,j,'P'); 
                }
                if(i == m-1 || j == n-1){
                    dfs(heights,i,j,'A'); 
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                List<Integer> container = new ArrayList<>(); 

                if(pacific[i][j] && atlantic[i][j]){
                    container.add(i);
                    container.add(j); 
                    answer.add(container); 
                }
            }
        }



        return answer; 
    }

    public void dfs(int[][] heights, int i, int j, char ocean){
        
        if(ocean == 'P') pacific[i][j] = true;
        if(ocean == 'A') atlantic[i][j] = true; 

        for(int[] d : dir){
            int nX = i + d[0]; 
            int nY = j + d[1]; 
            if(nX >= 0 && nY >= 0 && nX < heights.length && nY < heights[0].length && heights[i][j] <= heights[nX][nY]){
                if(ocean == 'P' && pacific[nX][nY] != true ) dfs(heights,nX,nY,ocean); 
                if(ocean == 'A' && atlantic[nX][nY] != true) dfs(heights,nX,nY,ocean); 
            }
        }
    }
}