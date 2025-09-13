class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        int n = nums.size();
        
        // dp[i][j] = can we make sum j using first i items?
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        
        // Base case: can always make sum 0 (pick nothing)
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        
        for(int i = 1; i <= n; i++){
            int num = nums[i-1];  // Row i uses item at index i-1
            for(int j = 1; j <= target; j++){
                // Don't take current item
                dp[i][j] = dp[i-1][j];
                
                // Take current item (if possible)
                if(j >= num){
                    //dp[i][j] = dp[i][j] || dp[i-1][j-num];
                    if(dp[i][j] == true) continue; 
                    dp[i][j] = dp[i-1][j-num]; 
                }
            }
        }
        
        return dp[n][target];
    }
};