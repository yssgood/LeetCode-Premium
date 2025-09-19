class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        vector<vector<int>> ourVec(n+1, vector<int>(amount+1,INT_MAX-1));
        for (int i = 0; i <= n; i++){
            ourVec[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= amount; j++){
                int currcoin = coins[i-1];
                int unchoose = ourVec[i-1][j];
                if (j >= currcoin && ourVec[i][j-currcoin] != INT_MAX-1){
                    int choose = 1 + ourVec[i][j-currcoin];
                    //before you choose, add condition to prevent negative index
                    if (choose < unchoose){
                        ourVec[i][j] = choose;
                    } else{
                        ourVec[i][j] = unchoose;
                    }
                    //ourVec[i][j] = min(choose, unchoose); 
                } else{
                    ourVec[i][j] = unchoose;   
                }
            }
        }
        
        if (ourVec[n][amount] == INT_MAX-1){
            return -1;
        }
        return ourVec[n][amount];
    }
};