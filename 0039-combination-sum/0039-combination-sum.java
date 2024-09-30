class Solution {
    void dfs(int[] candidates, List<List<Integer>> answer, List<Integer> container, int target, int index){
        if(target <= 0){
            //System.out.println(container + " " +  target);  
            if(target == 0){
                answer.add(new ArrayList<>(container)); 
                //System.out.println(container + " " +  target);  
            }
            return; 
        }
        for(int i = index; i < candidates.length; i++){
            target -= candidates[i]; 
            container.add(candidates[i]); 
            dfs(candidates, answer, container, target, i); 
            target += candidates[i];
            container.removeLast(); 
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer = new ArrayList<>(); 
        List<Integer> container = new ArrayList<>(); 
        dfs(candidates,answer,container,target,0);
        return answer; 
    }
}