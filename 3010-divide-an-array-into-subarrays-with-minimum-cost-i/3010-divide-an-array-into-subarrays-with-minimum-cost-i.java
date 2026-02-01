class Solution {
    public int minimumCost(int[] nums) {
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        
        // nums[1:]에서 최소 2개 찾기
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] < min1) {
                min2 = min1;  // 기존 min1을 min2로
                min1 = nums[i];
            } else if(nums[i] < min2) {
                min2 = nums[i];
            }
        }
        
        return nums[0] + min1 + min2;
    }
}