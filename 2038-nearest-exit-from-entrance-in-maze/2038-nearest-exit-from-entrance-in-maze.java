class Solution {
    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    public int nearestExit(char[][] maze, int[] entrance) {
        Queue<int[]> q = new LinkedList<>(); 
        q.add(new int[]{entrance[0],entrance[1],0}); 
        maze[entrance[0]][entrance[1]] = '+'; 

        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int[] front = q.poll(); 

                int x = front[0], y = front[1], dist = front[2]; 
                
                for(int[] d : dir){
                    int nX = x + d[0];
                    int nY = y + d[1]; 

                    if(nX < 0 || nY < 0 || nX >= maze.length || nY >= maze[0].length || maze[nX][nY] == '+') continue; 

                    if(nX == 0 || nX == maze.length-1 || nY == 0 || nY == maze[0].length-1) return dist + 1; 

                    maze[nX][nY] = '+'; 
                    q.add(new int[]{nX,nY,dist+1}); 
                }
            }
        }

        return -1; 
    }
}