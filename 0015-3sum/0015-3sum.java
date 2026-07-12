class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums); 
        List<List<Integer>> answer = new ArrayList<>(); 

        for(int i = 0; i < nums.length - 2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int start = i + 1, end = nums.length-1; 
            int curr = nums[i]; 
            while(start < end){
                int sum = curr + nums[start] + nums[end]; 
                
                if(sum > 0){
                    end--; 
                } else if(sum < 0){
                    start++; 
                } else{
                    while(start < end && nums[start] == nums[start+1]) start++; 
                    answer.add(Arrays.asList(curr, nums[start], nums[end])); 
                    start++;
                    end--; 
                }
            }
        }

        return answer; 
    }
}