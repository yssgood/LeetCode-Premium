class Solution {
public:
    int numSquares(int n) {
        if(n <= 1) return 1; 

        vector<int> dp(n+1,INT_MAX); 
        dp[1] = 1; 

        for(int i = 2; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                if(j * j == i){
                    dp[i] = 1;
                    break; 
                } else{
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }

        return dp[n]; 
    }
};