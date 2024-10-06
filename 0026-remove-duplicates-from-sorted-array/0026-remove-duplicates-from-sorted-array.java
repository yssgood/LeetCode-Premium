class Solution {
    public int removeDuplicates(int[] nums) {
        int curr = nums[0]; 
        int start = 1; 
        for(int i = start; i < nums.length; i++){
            if(nums[i] != curr){
                nums[start++] = nums[i];
                curr = nums[i]; 
            }
        }
        return start; 
    }
}