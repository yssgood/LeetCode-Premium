class Solution {
    int[][] dir = new int[][]{{0,1},{0,-1},{1,0},{-1,0}}; 
    public void wallsAndGates(int[][] rooms) {
        Queue<int[]> q = new LinkedList<>(); 
        for(int i = 0; i < rooms.length; i++){
            for(int j = 0; j < rooms[i].length; j++){
                if(rooms[i][j] == 0){
                    q.offer(new int[]{i,j,0}); 
                }
            }
        }
        
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int[] curr = q.poll(); 
                int x = curr[0]; 
                int y = curr[1]; 
                int dist = curr[2]; 

                for(int[] p : dir){
                    int nX = x + p[0];
                    int nY = y + p[1]; 

                    if(nX < 0 || nY < 0 || nX >= rooms.length || nY >= rooms[0].length || rooms[nX][nY] == -1) continue; 

                    if(rooms[nX][nY] > dist + 1){
                        rooms[nX][nY] = dist + 1; 
                        q.offer(new int[]{nX,nY,dist+1}); 
                    }
                }
            }
        }
    }
}