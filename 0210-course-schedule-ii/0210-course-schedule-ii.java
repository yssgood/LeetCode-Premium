class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }

        int[] indegree = new int[numCourses]; 

        for(int[] p : prerequisites){
            int to = p[0];
            int from = p[1]; 

            adj.get(from).add(to);
            indegree[to]++; 
        }

        Queue<Integer> q = new LinkedList<>(); 

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.add(i); 
            }
        }

        if(q.isEmpty()) return new int[]{}; 
        List<Integer> answer = new ArrayList<>(); 
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int curr = q.poll(); 
                answer.add(curr); 
                for(int next : adj.get(curr)){
                    indegree[next]--; 
                    if(indegree[next] == 0){
                        q.add(next); 
                    }
                }
            }
        }

        if(answer.size() != numCourses) return new int[]{}; 


        return answer.stream().mapToInt(Integer::intValue).toArray(); 
    }
}