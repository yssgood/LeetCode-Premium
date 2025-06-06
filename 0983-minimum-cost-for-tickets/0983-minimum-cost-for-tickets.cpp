class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(days.begin(), days.end()); 
        vector<int> dp(366,0); 

        for(int day = 1; day <= 365; day++){
            if(!travelDays.count(day)){
                dp[day] = dp[day-1];  
            } else{
                int cost1 = dp[day-1] + costs[0]; 
                int cost2 = dp[max(0,day-7)] + costs[1];  
                int cost3 = dp[max(0,day-30)] + costs[2]; 

                dp[day] = min({cost1,cost2,cost3}); 
            }
        }

        return dp[365]; 
    }
};