class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() <= 1) return 1; 
        sort(pairs.begin(), pairs.end()); 
        vector<int> dp(1001,1); 
        for(int i = 1; i < pairs.size(); i++){
            int c = pairs[i][0], d = pairs[i][1]; 
            for(int j = 0; j < i; j++){
                int a = pairs[j][0], b = pairs[j][1]; 
                if(b < c){
                    dp[i] = max(dp[j] + 1, dp[i]); 
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); 
    }
};