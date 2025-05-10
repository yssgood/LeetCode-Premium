class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return 1; 
        int n = nums.size(); 
        int max_ = 1; 
        vector<int> dp(n,1); 

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1); 
                    max_ = max(max_, dp[i]); 
                }
            }
        }

        return max_; 
    }
};