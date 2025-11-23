class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 
        int index = 0;
        dfs(answer,container,index,nums);
        return answer; 
    }
    void dfs(List<List<Integer>> answer,  List<Integer> container, int index, int[] nums){
        answer.add(new ArrayList<>(container)); 
        for(int i = index; i < nums.length; i++){
            container.add(nums[i]);
            dfs(answer,container,i+1,nums); 
            container.removeLast(); 
        }
    }
}