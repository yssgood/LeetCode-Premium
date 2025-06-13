class Solution {
    public int minimizeMax(int[] nums, int p) {
        if (p == 0) return 0;
        
        Arrays.sort(nums);
        int n = nums.length;
        
        int left = 0, right = nums[n-1] - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canFormPairsDP(nums, p, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

    private boolean canFormPairsDP(int[] nums, int p, int maxDiff) {
        int n = nums.length;
        // dp[i] = maximum pairs we can form using first i elements
        int[] dp = new int[n + 1];
        
        for (int i = 2; i <= n; i++) {
            // Option 1: Don't pair nums[i-1] with nums[i-2]
            dp[i] = dp[i-1];
            
            // Option 2: Pair nums[i-1] with nums[i-2] if difference <= maxDiff
            if (nums[i-1] - nums[i-2] <= maxDiff) {
                dp[i] = Math.max(dp[i], dp[i-2] + 1);
            }
        }
        
        return dp[n] >= p;
    }
}