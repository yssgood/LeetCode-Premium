class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            int find = target - nums[i]; 
            if(hashMap.containsKey(find)){
                return new int[]{hashMap.get(find),i}; 
            }
            hashMap.put(nums[i],i); 
        }
        return new int[]{}; 
    }
}