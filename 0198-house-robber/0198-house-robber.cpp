class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0]; 
        if(nums.size() <= 2) return max(nums[0], nums[1]); 


        vector<int> dp(nums.size(),0); 
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 
        
        int n = nums.size(); 
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]); 
        }

        return dp[n-1]; 
    }
};