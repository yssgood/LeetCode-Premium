class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(numCourses <= 1) return true; 
        if(prerequisites.length == 0) return true; 

        int[] inOrder = new int[numCourses]; 
        List<List<Integer>> adj = new ArrayList<>(); 

        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int[] p : prerequisites){
            int from = p[1];  
            int to = p[0]; 
            
            
            adj.get(from).add(to); 
            inOrder[to]++; 
        }

        Queue<Integer> q = new LinkedList<>(); 
        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0) q.offer(i); 
        }

        if(q.isEmpty()) return false; 
        
        int count = 0; 
        while(!q.isEmpty()){
            int size = q.size(); 
            count++; 
            int curr = q.poll(); 
            for(int next : adj.get(curr)){
                inOrder[next]--; 
                if(inOrder[next] == 0){
                    q.offer(next);
                }
            }
        }

        return count == numCourses;
    }
}