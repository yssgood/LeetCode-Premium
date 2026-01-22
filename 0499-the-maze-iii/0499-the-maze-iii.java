class Solution {
    class Ball {
        int x, y; 
        int dist; 
        StringBuilder instruction; 
        public Ball(int x, int y, int dist, StringBuilder instruction){
            this.x = x;
            this.y = y; 
            this.dist = dist;
            this.instruction = instruction; 
        }
    }

    int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
    char[] letter = {'r','l','d','u'}; 
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        int m = maze.length;
        int n = maze[0].length; 
        int[][][] visited = new int[m][n][4]; 
        StringBuilder answer = new StringBuilder("~");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                Arrays.fill(visited[i][j], Integer.MAX_VALUE); 
            }
        }

        for(int i = 0; i < 4; i++){
            visited[ball[0]][ball[1]][i] = 0; 
        }

        Queue<Ball> q = new LinkedList<>(); 
        q.add(new Ball(ball[0], ball[1], 0, new StringBuilder())); 

        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Ball first = q.poll(); 
                int x = first.x, y = first.y, dist = first.dist; 
                StringBuilder inst = first.instruction; 

                for(int k = 0; k < 4; k++){
                    int nX = x + dir[k][0]; 
                    int nY = y + dir[k][1]; 
                    int nDist = dist; 
                    StringBuilder nInst = new StringBuilder(inst).append(letter[k]); 
                    while(nX >= 0 && nY >= 0 && nX < m && nY < n && maze[nX][nY] != 1){
                        if(nX == hole[0] && nY == hole[1]){
                            if(nInst.toString().compareTo(answer.toString()) < 0){
                                answer = nInst; 
                            }
                        }
                        nX += dir[k][0];
                        nY += dir[k][1]; 
                        nDist += 1; 
                    }

                    nX -= dir[k][0];
                    nY -= dir[k][1]; 
                    //nDist -= 1? 

                    if(visited[nX][nY][k] > nDist){
                        visited[nX][nY][k] = nDist; 
                        q.add(new Ball(nX,nY,nDist,new StringBuilder(nInst))); 
                    }
                }
            }
        }

        return answer.toString().equals("~") ? "impossible" : answer.toString();
    }
}