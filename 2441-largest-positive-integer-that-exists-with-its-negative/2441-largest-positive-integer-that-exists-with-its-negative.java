class Solution {
    public int findMaxK(int[] nums) {
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        int answer = 0; 
        for(int n : nums){
            int target = n * -1; 
            if(hashMap.containsKey(target)){
                answer = Math.max(answer, Math.abs(target)); 
            }
            hashMap.put(n,1); 
        }

        return answer == 0 ? -1 : answer; 
    }
}