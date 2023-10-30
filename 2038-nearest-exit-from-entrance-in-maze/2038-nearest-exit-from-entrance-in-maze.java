class Solution {
    public static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public int nearestExit(char[][] maze, int[] entrance) {
        Queue<int[]> q = new LinkedList<>(); 
        boolean visited[][] = new boolean[maze.length][maze[0].length]; 

        q.add(new int[]{entrance[0], entrance[1],0}); 

        visited[entrance[0]][entrance[1]] = true; 

        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){

                int[] first = q.poll(); 

                int x = first[0], y = first[1], dist = first[2]; 

                //if((x != entrance[0] && y != entrance[1]) && (x == maze.length-1 || x == 0 || y == 0 || y == maze[0].length-1)) return dist; 
                
                if(dist > 0 && x == maze.length-1 || dist > 0 && x == 0 || dist > 0 && y == maze[0].length-1 || dist > 0 && y == 0) return dist; 

                for(int[] p : dir){

                    int nX = x + p[0]; 
                    int nY = y + p[1]; 
                    
                    if(nX < 0 || nX >= maze.length || nY < 0 || nY >= maze[0].length || visited[nX][nY] || maze[nX][nY] == '+') continue; 

                    visited[nX][nY] = true; 
                    q.add(new int[]{nX,nY,dist+1}); 
                }


            }
        }


        return -1; 
    }
}