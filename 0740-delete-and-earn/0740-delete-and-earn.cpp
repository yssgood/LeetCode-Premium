class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //2 3 4 5
        vector<int> dp(10001);
        for(int n : nums) dp[n] += n; 
        int max_ = dp[1]; 
        for(int i = 2; i < dp.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + dp[i]); 
            max_ = max(max_, dp[i]); 
        }

        return max_; 
    }
};