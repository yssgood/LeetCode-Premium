class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> answer = new ArrayList<>();
        int start = 0, end = 0; 
        StringBuilder sb = new StringBuilder(); 
        while(end < nums.length){
            int curr = nums[end]; 
            int last = nums[end]; 
            while(end + 1 < nums.length && nums[end+1] - nums[end] == 1){
                end++; 
                last = nums[end]; 
            }

            if(curr != last){
                sb.append(Integer.toString(curr)).append("->").append(Integer.toString(last));
            } else{
                sb.append(Integer.toString(curr)); 
            }

            answer.add(sb.toString()); 
            sb = new StringBuilder(); 
            end++; 
        }
        return answer; 
    }
}