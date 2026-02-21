class Solution {
    Map<Integer, List<Integer>> hashMap; 

    public Solution(int[] nums) {
        hashMap = new HashMap<>(); 
        for(int i = 0; i < nums.length; i++){
            hashMap.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i); 
        }
    }
    
    public int pick(int target) {
        List<Integer> lst = hashMap.get(target); 
        int randomIndex = (int)(Math.random() * lst.size()); 
        return lst.get(randomIndex); 
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */