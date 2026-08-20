class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        //-2 -1 0 1 2 
        List<List<Integer>> answer = new ArrayList<>(); 
        Arrays.sort(nums); 
        for(int i = 0; i < nums.length-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue; 
            int first = nums[i]; 
            for(int j = i + 1; j < nums.length-2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue; 
                int second = nums[j]; 
                int start = j + 1, end = nums.length-1; 
                while(start < end){
                    int third = nums[start]; 
                    int fourth = nums[end]; 
                    long sum = (long)first + second + third + fourth; 
                    if(sum > target){
                        end--; 
                    } else if(sum < target){
                        start++; 
                    } else{
                        while(start + 1< end && nums[start] == nums[start+1]) start++; 
                        answer.add(List.of(first,second,third,fourth)); 
                        start++;
                        end--; 
                    }
                }
            }
        }
        return answer; 
    }
}