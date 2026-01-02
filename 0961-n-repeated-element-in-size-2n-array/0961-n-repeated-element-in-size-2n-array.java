class Solution {
    public int repeatedNTimes(int[] nums) {
        int target = nums.length / 2; 
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int n : nums) hashMap.put(n, hashMap.getOrDefault(n,0) + 1); 
        for(Map.Entry<Integer,Integer> entry :  hashMap.entrySet()){
            if(entry.getValue() == target) return entry.getKey(); 
        }
        return -1; 
    }
}