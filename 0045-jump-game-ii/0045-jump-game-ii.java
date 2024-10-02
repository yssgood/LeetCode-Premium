class Solution {

    class Pair{
        int first, second; 

        public Pair(int first, int second){
            this.first = first; 
            this.second = second; 
        }
    }
    public int jump(int[] nums) {
        if(nums.length == 1
        ) return 0; 
        Queue<Pair> q = new LinkedList<>(); 
        boolean[] visited = new boolean[nums.length]; 

        q.offer(new Pair(0,0)); 
        visited[0] = true; 
        
        while(!q.isEmpty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Pair p = q.poll(); 
                int curr = p.first, dist = p.second; 
                for(int j = 1; j <= nums[curr]; j++){
                    if(curr + j >= nums.length-1) return dist+1; 
                    if(!visited[curr + j]){
                        visited[curr + j] = true; 
                        q.offer(new Pair(curr + j, dist + 1)); 
                    }
                }
            }
        }

        return 0; 
    }
}