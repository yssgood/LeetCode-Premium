class Solution {
public:
    int memo[1001]; 
    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo,-1,sizeof(memo)); 
        return min(solution(cost,cost.size()-1), solution(cost,cost.size()-2)); 
    }

    int solution(vector<int>& cost,int index){
        if(index <= 1) return cost[index]; 

        int& ret = memo[index];
        if(ret > -1) return memo[index]; 


        ret = min(solution(cost,index-1), solution(cost,index-2)) + cost[index]; 

        return ret; 
    }
};