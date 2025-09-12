class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> memo(n,-1); 
        return min(solve(n-1,cost,memo), solve(n-2,cost,memo));  
    }

    int solve(int index, vector<int>& cost, vector<int>& memo){
        if(index == 0) return cost[0]; 
        if(index == 1) return cost[1];

        if(memo[index] != -1) return memo[index]; 

        int firstStep = solve(index-1,cost,memo); 
        int secondStep = solve(index-2,cost,memo); 

        memo[index] = min(firstStep, secondStep) + cost[index]; 
        return memo[index];  
    }
};