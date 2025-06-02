class Solution {
public:
    int memo[1001]; 
    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo,-1,sizeof(memo)); 
        return solution(cost, cost.size()); 
    }

    int solution(vector<int>& cost, int n){
        if(n <= 1) return 0; 

        int& ret = memo[n]; 
        if(ret > -1) return memo[n]; 


         ret = min(solution(cost,n-1) + cost[n-1], solution(cost,n-2) + cost[n-2]);

        return ret; 
    }
};