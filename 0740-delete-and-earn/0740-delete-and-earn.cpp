class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        unordered_map<int,int> hashMap; 
        int max_ = *max_element(nums.begin(), nums.end());
        for(int n : nums) hashMap[n] += n; 
        vector<int> dp(max_ + 1,0); 
        for(int i = 1; i <= max_; i++){
            dp[i] = max(dp[i-1], dp[max(0,i-2)] + hashMap[i]); 
        }

        return dp[max_]; 
    }
};