class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 
        dfs(nums,answer,container,0); 
        return answer; 
    }
    void dfs(int[] nums, List<List<Integer>> answer, List<Integer> container, int index){
        answer.add(new ArrayList<>(container)); 
        for(int i = index; i < nums.length; i++){
            container.add(nums[i]); 
            dfs(nums,answer,container,i+1);
            container.removeLast();
        }
    }
}