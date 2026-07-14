class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            int curr = nums[i]; 
            if(hashMap.containsKey(curr) && Math.abs(hashMap.get(curr) - i) <= k) return true; 
            hashMap.put(curr,i); 
        }
        return false; 
    }
}