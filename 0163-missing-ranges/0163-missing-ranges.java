class Solution {
    public List<List<Integer>> findMissingRanges(int[] nums, int lower, int upper) {
        List<List<Integer>> answer = new ArrayList<>(); 


        if(nums.length == 0){
            answer.add(Arrays.asList(lower,upper)); 
            return answer; 
        }

        if(lower < nums[0]){
            answer.add(Arrays.asList(lower,nums[0]-1)); 
        }
        
        int n = nums.length-1; 
        for(int i = 0; i < n; i++){
            if(nums[i+1] - nums[i] <= 1) continue; 
            answer.add(Arrays.asList(nums[i]+1, nums[i+1]-1));
        }

        if(nums[n] < upper){
            answer.add(Arrays.asList(nums[n]+1,upper)); 
        }

        return answer; 
    }
}