class Solution {
public:
    int memo[46];
    int climbStairs(int n) {
        memset(memo,-1,sizeof(memo)); 
        return solution(n); 
    }

    int solution(int n){
        if(n <= 1) return 1; 

        int& ret = memo[n]; 
        if(ret > -1) return memo[n]; 

        ret = solution(n-1) + solution(n-2);

        return ret; 
    }
};