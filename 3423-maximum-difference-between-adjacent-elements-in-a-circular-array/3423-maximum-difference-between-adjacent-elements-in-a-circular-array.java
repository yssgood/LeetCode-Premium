class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int max_ = Math.abs(nums[nums.length-1] - nums[0]); 
        int n = nums.length; 
        for(int i = 0; i + 1 < n; i++){
            int compare = Math.abs(nums[i] - nums[i+1]); 
            max_ = Math.max(max_,compare); 
        }
        return max_; 
    }
}