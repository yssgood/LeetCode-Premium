class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        int n = nums.size();
        
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        
        // Base case: can always make sum 0
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        // Base case: first item
        for(int i = 1; i <= target; i++){
            if(i == nums[0]) dp[0][i] = true; 
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j < nums[i]) {
                    dp[i][j] = dp[i-1][j];
                } 
                else if(j == nums[i]) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
            }
        }
        
        return dp[n-1][target];
    }
};