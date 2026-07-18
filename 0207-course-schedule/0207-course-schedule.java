class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] inOrder = new int[numCourses]; 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }
        for(int[] pre : prerequisites){
            int to = pre[0]; 
            int from = pre[1]; 

            inOrder[to]++; 
            adj.get(from).add(to); 
        }

        Queue<Integer> q = new LinkedList<>(); 
        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0) q.add(i); 
        }

        if(q.isEmpty()) return false; 

        int num = 0; 

        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int node = q.poll();
                num++; 
                for(int next : adj.get(node)){
                    inOrder[next]--; 
                    if(inOrder[next] == 0){
                        q.add(next); 
                    }
                }
            }
        }

        return num == numCourses; 
    }
}