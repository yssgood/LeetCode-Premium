class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int> hashSet(days.begin(),days.end()); 
        vector<int> dp(366,INT_MAX); 

        dp[0] = 0; 

        for(int i = 1; i <= 365; i++){
            if(!hashSet.count(i)){
                dp[i] = dp[i-1]; 
            } else{
                dp[i] = min(dp[i],dp[i-1] + costs[0]); 
                dp[i] = min(dp[i],dp[max(0,i-7)] + costs[1]); 
                dp[i] = min(dp[i],dp[max(0,i-30)] + costs[2]); 
            }
        }


        return dp[365]; 
    }
};