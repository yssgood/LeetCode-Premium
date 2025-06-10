class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length; 
        if(n <= 1) return 1; 

        int[] dp = new int[n]; 
        int[] count = new int[n]; 
        int max_ = 1; 
        int answer = 0; 

        Arrays.fill(dp,1); 
        Arrays.fill(count,1); 

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 == dp[i]){
                        count[i] += count[j]; 
                    } else if(dp[j] +1 > dp[i]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1); 
                        count[i] = count[j]; 
                    }
                    max_ = Math.max(max_,dp[i]); 
                } 
            }
        }

        for(int i = 0; i < n; i++){
            if(dp[i] == max_) answer += count[i]; 
        }

        return answer; 
    }
}