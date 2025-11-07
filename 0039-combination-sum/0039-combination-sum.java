class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 
        dfs(candidates, target, answer, container, 0); 
        return answer; 
    }
    void dfs(int[] candidates, int target, List<List<Integer>> answer, List<Integer> container, int index){
        if(target <= 0){
            if(target == 0) answer.add(new ArrayList<>(container)); 
            return; 
        }

        for(int i = index; i < candidates.length; i++){
            target -= candidates[i]; 
            container.add(candidates[i]); 
            dfs(candidates, target, answer, container, i); 
            target += candidates[i]; 
            container.removeLast();  
        }
    }
}