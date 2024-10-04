class Solution {
    int[][] dir = new int[][]{{0,1},{0,-1},{1,0},{-1,0}}; 
    class Ball{
        int x, y, dist; 
        public Ball(int x, int y, int dist){
            this.x = x;
            this.y = y; 
            this.dist = dist; 
        }
    }
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        Queue<Ball> q = new LinkedList<>(); 
        int[][] visited = new int[maze.length][maze[0].length]; 
        for(int i = 0; i < maze.length; i++){
            Arrays.fill(visited[i],Integer.MAX_VALUE); 
        }
        q.offer(new Ball(start[0],start[1],0)); 
        visited[start[0]][start[1]] = 0; 
        int answer = Integer.MAX_VALUE; 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Ball curr = q.poll(); 
                int x = curr.x;  
                int y = curr.y;
                int dist = curr.dist; 

                if(x == destination[0] && y == destination[1]){
                    answer = Math.min(answer, dist); 
                }

                for(int[] p : dir){
                    int nX = x + p[0];
                    int nY = y + p[1]; 
                    int nDist = dist; 
                    while(nX >= 0 && nY >= 0 && nX < maze.length && nY < maze[0].length && maze[nX][nY] != 1){
                        nX += p[0];
                        nY += p[1]; 
                        nDist++; 
                    }

                    nX -= p[0]; 
                    nY -= p[1]; 
                    //nDist--; 

                    if(visited[nX][nY] > nDist){
                        //System.out.println(nX + " " + nY + " " + nDist); 
                        visited[nX][nY] = nDist; 
                        q.offer(new Ball(nX,nY,nDist)); 
                    }
                }
            }
        }
        return answer == Integer.MAX_VALUE ? -1 : answer; 
    }
}