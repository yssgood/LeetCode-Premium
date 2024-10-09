class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //-2 -1 1 2 
        Arrays.sort(nums); 
        List<List<Integer>> answer = new ArrayList<>(); 
        for(int i = 0; i < nums.length-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int curr = nums[i]; 
            int start = i + 1;
            int end = nums.length-1;
            while(start < end){
                int second = nums[start];
                int third = nums[end]; 
                int sum = curr + second + third; 

                if(sum < 0){
                    start++; 
                } else if(sum > 0){
                    end--; 
                } else{
                    while(start < end && nums[start] == nums[start+1]) start++;
                    while(start < end && nums[end] == nums[end-1]) end--; 
                    List<Integer> tmp = new ArrayList<>(); 
                    tmp.add(curr);
                    tmp.add(second); 
                    tmp.add(third);
                    answer.add(tmp); 
                    start++;
                    end--; 
                }
            }
        }

        return answer; 
    }
}