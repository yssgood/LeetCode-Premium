class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //amount 11
        //0 0 0 0 0 0 0 0 0 0 

        vector<int> dp(amount + 1, INT_MAX - 1); 
        dp[0] = 0; 
        
        for(int i = 1; i<= amount; i++){
            for(int coin : coins){
                if(coin > i) continue; 
                //if(i == amount) cout << dp[i % coin]; 
                //dp[i] = min(dp[i], (i / coin) + dp[i % coin]); 
                dp[i] = min(dp[i], dp[i-coin] + 1); 
            }
        }

        // for(int i = 1; i <= amount; i++){
        //     cout << dp[i] << ' '; 
        // }


        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount]; 
    }
};


/*
        //amount 2 
        //[1,2,5] => 1
        

        //amount 1 
        //[1,2,5] => 1
        //[1,-1,-1] 
        
        //amount 2 
        //[1,2,5] => 1
        //[2,1,-1] 

        //amount 3 
        //[1,2,5]
        //[3,2,-1] 

        //amount 4 
        //[4,2,-1] 

        //amount 5 
        //[5,3,1] 

        //amount 6 
        //[6,3,2] 

        //amount 7 
        //[7,4,2] 
*/