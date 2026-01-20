class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            int n = nums[i]; 
            if(hashMap.containsKey(target - n)) return new int[]{hashMap.get(target - n), i}; 
            hashMap.put(n, i); 
        }
        return new int[]{};
    }
}