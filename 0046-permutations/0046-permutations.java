class Solution {
    void dfs(int[] nums, List<List<Integer>> answer, List<Integer> container,boolean[] visited){
        if(container.size() >= nums.length){
            answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = 0; i < nums.length; i++){
            if(!visited[i]){
                visited[i] = true; 
                container.add(nums[i]); 
                dfs(nums,answer,container,visited); 
                container.remove(container.size()-1); 
                visited[i] = false; 
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 
        boolean[] visited = new boolean[nums.length]; 
        dfs(nums,answer,container,visited);
        return answer; 
    }
}