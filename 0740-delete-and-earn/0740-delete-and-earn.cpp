class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        map<int,int> hashMap; 
        int max_ = *max_element(nums.begin(), nums.end()); 
        for(int n : nums) hashMap[n] += n; 
        vector<int> dp(max_ + 1, 0); 
        dp[1] = hashMap[1]; 
        for(int i = 2; i <= max_; i++){
            dp[i] = max(dp[i-1], dp[i-2] + hashMap[i]); 
        }
        return dp[max_]; 
    }
};