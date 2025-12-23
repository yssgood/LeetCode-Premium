class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> answer = new ArrayList<>(); 
        int end = 0; 
        while(end < nums.length){
            int curr = nums[end]; 
            int start = nums[end]; 
            while(end + 1 < nums.length && nums[end+1] - curr == 1){
                curr = nums[end+1];
                end++;  
            }

            if(start == nums[end]){
                answer.add(String.valueOf(nums[end])); 
            } else{
                answer.add(String.valueOf(start) + "->" + String.valueOf(curr)); 
            }

            end++; 
        }
        return answer; 
    }
}