class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1); 
        int max_ = 1; 
        for(int i = 1; i < nums.size(); i++){
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