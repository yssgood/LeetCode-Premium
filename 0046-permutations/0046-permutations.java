class Solution {
    boolean[] visited = new boolean[11]; 
    public void dfs(List<List<Integer>> answer, List<Integer> container, int[] nums){
        if(container.size() >= nums.length){
            answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = 0; i < nums.length; i++){
            if(!visited[i]){
                visited[i] = true; 
                container.add(nums[i]); 
                dfs(answer, container, nums);
                visited[i] = false; 
                container.removeLast(); 
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 

        dfs(answer, container, nums); 

        return answer; 
    }
}