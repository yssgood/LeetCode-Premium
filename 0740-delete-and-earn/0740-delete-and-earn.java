class Solution {
    public int deleteAndEarn(int[] nums) {
        if(nums.length == 1) return nums[0]; 
        Map<Integer,Integer> hashMap = new HashMap<>(); 
        int max_ = 0; 
        for(int n : nums){
            max_ = Math.max(max_, n); 
            hashMap.put(n, hashMap.getOrDefault(n,0) + 1); 
        }

        int[] dp = new int[max_ + 1]; 
        dp[1] = 1 * hashMap.getOrDefault(1,0); 

        int answer = dp[1]; 
        for(int i = 2; i <= max_; i++){
            dp[i] = Math.max(dp[i-2] + i * hashMap.getOrDefault(i,0), dp[i-1]); 
            answer = Math.max(answer, dp[i]);
        }
        return answer; 

    }
}