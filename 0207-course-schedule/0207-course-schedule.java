class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj =  new ArrayList<>(); 
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }

        int[] inOrder = new int[numCourses]; 
        for(int[] course : prerequisites){
            int to = course[0], from = course[1]; 
            adj.get(from).add(to); 
            inOrder[to]++; 
        }

        Queue<Integer> q = new LinkedList<>(); 
        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0) q.offer(i); 
        }
        if(q.isEmpty()) return false; 

        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int curr = q.poll(); 
                for(int next : adj.get(curr)){
                    inOrder[next]--; 
                    if(inOrder[next] == 0){
                        q.offer(next); 
                    }
                }
            }
        }
        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] > 0) return false; 
        }
        return true; 
    }
}