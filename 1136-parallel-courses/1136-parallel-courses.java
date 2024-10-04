class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        Queue<Integer> q = new LinkedList<>(); 
        int[] inDegree = new int[n+1]; 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i <= n; i++){
            adj.add(new ArrayList<>()); 
        }
        for(int[] p : relations){
            int prev = p[0]; 
            int next = p[1]; 
            adj.get(prev).add(next); 
            inDegree[next]++; 
        }

        for(int i = 1; i <= n; i++){
            if(inDegree[i] == 0){
                q.offer(i); 
            }
        }

        if(q.isEmpty()) return -1; 
        int term = 0; 
        while(!q.isEmpty()){
            int size = q.size();
            term++;  
            for(int i = 0; i < size; i++){
                int curr = q.poll(); 
                for(int nextNode : adj.get(curr)){
                    inDegree[nextNode]--;
                    if(inDegree[nextNode] <= 0){
                        q.offer(nextNode); 
                    }
                }
            }
        }

        return term; 
    }
}