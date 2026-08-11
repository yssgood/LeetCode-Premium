class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long answer = Long.MIN_VALUE; 
        Map<Integer,Long> hashMap = new HashMap<>(); 

        long currSum = 0; 
        for(int n : nums){
            int target = n - k; 
            hashMap.merge(n, currSum, Math::min); 
            currSum += n; 
            if(hashMap.containsKey(target)){
                //System.out.println(hashMap.get(target)); 
                answer = Math.max(answer, (currSum) - hashMap.get(target)); 
            }

            target = n + k; 
            if(hashMap.containsKey(target)){
                //System.out.println(hashMap.get(target)); 
                answer = Math.max(answer, (currSum) - hashMap.get(target)); 
            }
        }
        return answer == Long.MIN_VALUE ? 0 : answer; 
    }
}