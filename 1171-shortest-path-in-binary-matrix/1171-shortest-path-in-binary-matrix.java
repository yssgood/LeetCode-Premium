class Solution {
    public static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}}; 
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid[0][0] == 1) return -1; 
        int[][] visited = new int[grid.length][grid[0].length]; 
        for(int i = 0; i < visited.length; i++){
            Arrays.fill(visited[i],Integer.MAX_VALUE); 
        }
        Queue<int[]> q = new LinkedList<>(); 
        q.add(new int[]{0,0,1}); 
        visited[0][0] = 1; 
        while(!q.isEmpty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){

                int[] first = q.poll(); 

                int x = first[0], y = first[1], dist = first[2]; 

                for(int[] p : dir){
                    int nX = x + p[0]; 
                    int nY = y + p[1]; 

                    if(nX < 0 || nX >= grid.length || nY < 0 || nY >= grid[0].length || grid[nX][nY] == 1) continue; 

                    if(visited[nX][nY] > dist + 1){
                        visited[nX][nY] = dist + 1; 
                        q.add(new int[]{nX, nY, dist+1}); 
                    }
                }

            }
        }
        
        return visited[grid.length-1][grid[0].length-1] == Integer.MAX_VALUE ? -1 : visited[grid.length-1][grid[0].length-1];
    }
}