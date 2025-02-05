class Solution {
    public int longestConsecutive(int[] nums) {
        Map<Integer,Integer> hashMap = new HashMap<>();
        int answer = 0;  
        for(int n : nums) hashMap.put(n,1); 
        for(int n : nums){
            //hashMap.put(n, 0); 
            if(!hashMap.containsKey(n-1)){
                int streak = 1; 
                int curr = n; 
                while(hashMap.containsKey(curr + 1) && hashMap.get(curr + 1) > 0){
                    hashMap.put(curr + 1, 0); 
                    streak++; 
                    curr++; 
                }
                answer = Math.max(answer, streak); 
            }
        }
        return answer; 
    }
}