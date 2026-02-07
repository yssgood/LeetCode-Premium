class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length; 
        int[] dp = new int[n]; 
        int[] cnt = new int[n]; 

        Arrays.fill(dp,1); 
        Arrays.fill(cnt,1); 

        int max_ = 1; 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1; 
                        cnt[i] = cnt[j]; 
                    } else if(dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j]; 
                    }
                } 
                max_ = Math.max(dp[i], max_); 
            }
        }


        int answer = 0; 

        for(int i = 0; i < n; i++){
            if(dp[i] == max_) answer += cnt[i]; 
        }


        return answer; 
    }
}