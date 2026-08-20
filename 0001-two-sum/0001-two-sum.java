class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            int targetSum = target - nums[i]; 
            if(hashMap.containsKey(targetSum)) return new int[]{hashMap.get(targetSum), i}; 
            hashMap.put(nums[i],i); 
        }
        return new int[]{}; 
    }
}