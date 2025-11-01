class Solution {
    public int longestConsecutive(int[] nums) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        for(int n : nums) hashMap.put(n, hashMap.getOrDefault(n,0) + 1); 
        int max_ = 0; 
        for(int n : nums){
            int curr = n; 
            if(!hashMap.containsKey(curr-1)){
                int streak = 0; 
                while(hashMap.containsKey(curr) && hashMap.get(curr) > 0){
                    hashMap.put(curr, hashMap.get(curr) -1); 
                    streak++; 
                    curr++; 
                }
                max_ = Math.max(max_, streak); 
            }
        }

        return max_; 
    }
}