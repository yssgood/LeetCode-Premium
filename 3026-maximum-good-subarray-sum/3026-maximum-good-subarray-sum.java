class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long preFix = 0; 
        long max_ = Long.MIN_VALUE;  
        Map<Integer,Long> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            preFix += nums[i]; 

            if(hashMap.containsKey(nums[i] + k)){
                max_ = Math.max(max_, preFix - hashMap.get(nums[i] + k)); 
            }
            if(hashMap.containsKey(nums[i] - k)){
                max_ = Math.max(max_, preFix - hashMap.get(nums[i] - k));
            }

            hashMap.put(nums[i], Math.min(hashMap.getOrDefault(nums[i], Long.MAX_VALUE), preFix - nums[i])); 
        }

        return max_ == Long.MIN_VALUE ? 0 : max_; 
    }
}