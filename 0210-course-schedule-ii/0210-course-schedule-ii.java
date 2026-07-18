class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer> answer = new ArrayList<>(); 
        int[] inOrder = new int[numCourses]; 
        List<List<Integer>> adj = new ArrayList<>(); 
        for(int i = 0; i < numCourses; i++){
            adj.add(new ArrayList<>()); 
        }

        for(int[] next : prerequisites){
            int to = next[0]; 
            int from = next[1]; 

            inOrder[to]++; 
            adj.get(from).add(to); 
        }

        Queue<Integer> q = new LinkedList<>(); 

        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0){
                q.add(i);
            }
        }

        if(q.isEmpty()) return new int[]{}; 


        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int node = q.poll();
                answer.add(node); 
                for(int next : adj.get(node)){
                    inOrder[next]--; 
                    if(inOrder[next] == 0){
                        q.add(next); 
                    }
                }
            }
        }

        if(answer.size() != numCourses) return new int[]{}; 
        
        return answer.stream().mapToInt(i -> i).toArray(); 
    }
}