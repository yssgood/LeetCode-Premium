class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dist = new int[n][k+2];  // CHANGE 1: k+2 instead of k+1
        for(int[] row : dist){
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0] - b[0]); 

        List<List<int[]>> adj = new ArrayList<>(); 
        for(int i = 0; i < n; i++) adj.add(new ArrayList<>()); 
        for(int[] flight : flights){
            int from = flight[0], to = flight[1], price = flight[2]; 
            adj.get(from).add(new int[]{to,price}); 
        }

        dist[src][k+1] = 0; 
        pq.offer(new int[]{0,src,k+1}); 

        while(!pq.isEmpty()){
            int[] curr = pq.poll(); 

            int currDist = curr[0], node = curr[1], leftDist = curr[2];
            
            // CHANGE 2: Add early return when destination reached
            if(node == dst) return currDist;

            for(int[] next : adj.get(node)){
                int nextNode = next[0]; 
                int weight = next[1]; 
                // CHANGE 3: Use leftDist-1 for comparison
                if(leftDist > 0 && dist[nextNode][leftDist-1] > currDist + weight){
                    dist[nextNode][leftDist-1] = currDist + weight; 
                    pq.offer(new int[]{dist[nextNode][leftDist-1], nextNode, leftDist-1}); 
                }
            }
        }

        return -1;  // CHANGE 4: Simple return -1
    }
}