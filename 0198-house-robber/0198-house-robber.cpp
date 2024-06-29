/*
Decision Making

The general problem statement for this pattern is forgiven situation decide whether to use or not to use the current state. 
So, the problem requires you to make a decision at a current state.

Statement
Given a set of values find an answer with an option to choose or ignore the current value.

Approach
If you decide to choose the current value use the previous result where the value was ignored; vice-versa, 
if you decide to ignore the current value use previous result where value was used.

*/ 

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        if(nums.size() == 2) return max(nums[0], nums[1]); 
        vector<int> dp(nums.size()); 
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 

        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]); 
        }

        return dp[nums.size()-1]; 
    }
};