/*
Patterns: 
Minimum (Maximum) Path to Reach a Target

Statement
Given a target find minimum (maximum) cost / path / sum to reach the target.

Approach
Choose minimum (maximum) path among all possible paths before the current state, then add value for the current state.
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()); 
        dp[0] = cost[0]; 
        dp[1] = cost[1]; 
        for(int i = 2; i < cost.size(); i++){
            //dp[i] = min(dp[i-1], dp[i-2]) + (i == cost.size()-1 ? 0 : cost[i]); ]
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]; 
        }
        return min(dp[cost.size()-1], dp[cost.size()-2]); 
    }
};