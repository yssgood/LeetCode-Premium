class Solution {
    public int minimumDifference(int[] nums, int k) {
        if(nums.length <= 1) return 0; 
        int minDiff = Integer.MAX_VALUE; 
        Arrays.sort(nums); 
        for(int i = 0; i <= nums.length - k; i++){
            int diff = nums[i + k - 1] - nums[i]; 
            minDiff = Math.min(minDiff, diff); 
        }
        return minDiff; 
    }
}