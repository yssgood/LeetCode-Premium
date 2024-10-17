class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int courses = 0; 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }

        int[] inWard = new int[numCourses]; 

        for(int[] p : prerequisites){
            int from = p[1]; 
            int to = p[0]; 

            adj.get(from).add(to); 
            inWard[to]++; 
        }

        Queue<Integer> q = new LinkedList<>(); 
        for(int i = 0; i < numCourses; i++){
            if(inWard[i] == 0) q.add(i); 
        }

        if(q.isEmpty()) return false; 

        while(!q.isEmpty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                courses++; 
                int curr = q.poll(); 

                for(int v : adj.get(curr)){
                    inWard[v]--; 
                    if(inWard[v] == 0){
                        q.add(v); 
                    }
                }
            }
        }


        return courses == numCourses ? true : false; 
    }
}