class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> dp; 
        int max_ = 2; 
        //for(int i = 1; i < nums.size(); i++) dp[0][nums[i] - nums[0]]++; 
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j]; 
                if(dp[j].count(diff)){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                    max_ = max(max_, dp[i][diff]); 
                } else{
                    dp[i][diff] = 2; 
                }
                // dp[i][res] += dp[j][res] + 1; 
                // max_ = max(max_,dp[i][res]); 
            }
        }
        return max_; 
    }
};