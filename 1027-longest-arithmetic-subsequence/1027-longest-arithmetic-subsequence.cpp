class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        map<int,map<int,int>> dp; 
        int max_ = 2; 
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j]; 
                if(dp[j].count(diff)){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1); 
                    max_ = max(max_, dp[i][diff]); 
                } else{
                    dp[i][diff] = 2; 
                }
            }
        }
        return max_; 
    }
};