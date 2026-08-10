class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums); 
        List<List<Integer>> answer = new ArrayList<>(); 
        for(int i = 0; i < nums.length-2; i++){
            int curr = nums[i]; 
            if(i > 0 && nums[i-1] == curr) continue; 
            int start = i+1, end = nums.length-1; 
            while(start < end){
                int second = nums[start];
                int third = nums[end]; 
                int sum = curr + second + third; 

                if(sum > 0){
                    end--;
                } else if(sum < 0){
                    start++; 
                } else{
                    while(start + 1 < end && nums[start] == nums[start+1]) start++; 
                    answer.add(List.of(curr,second,third)); 
                    start++;
                    end--; 
                }
            }
        }

        return answer; 
    }
}