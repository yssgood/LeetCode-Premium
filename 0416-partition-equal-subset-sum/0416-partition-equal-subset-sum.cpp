class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        int n = nums.size();
        
        // dp[i][j] = can we make sum j using items 0 to i?
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        
        // Base case: can always make sum 0 with any number of items
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        // Base case: first item can only make sum = nums[0]
        // if(nums[0] <= target) {
        //     dp[0][nums[0]] = true;
        // }
        for(int i = 1; i <= target; i++){
            if(i == nums[0]) dp[0][i] = true; 
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                // Option 1: don't take current item
                dp[i][j] = dp[i-1][j];
                
                // Option 2: take current item (if possible)  
                if(j >= nums[i]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i]];
                }
            }
        }
        
        return dp[n-1][target];
    }
};