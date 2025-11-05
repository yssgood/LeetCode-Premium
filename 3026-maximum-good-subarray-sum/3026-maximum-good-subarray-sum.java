class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long maxSum = Long.MIN_VALUE;
        Map<Integer, Long> map = new HashMap<>(); // value -> best prefix sum before it
        long prefixSum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            
            // case 1: nums[i] is the max, look for (nums[i] - k) as min
            if (map.containsKey(nums[i] - k)) {
                maxSum = Math.max(maxSum, prefixSum - map.get(nums[i] - k));
            }
            
            // case 2: nums[i] is the min, look for (nums[i] + k) as max
            if (map.containsKey(nums[i] + k)) {
                maxSum = Math.max(maxSum, prefixSum - map.get(nums[i] + k));
            }
            
            // update map: store minimum prefix sum seen before this value
            map.put(nums[i], Math.min(map.getOrDefault(nums[i], Long.MAX_VALUE), 
                                      prefixSum - nums[i]));
        }
        
        return maxSum == Long.MIN_VALUE ? 0 : maxSum;
    }
}