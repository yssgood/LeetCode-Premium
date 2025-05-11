class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() <= 1) return 1; 
        sort(pairs.begin(), pairs.end()); 
        int n = pairs.size(); 
        vector<int> dp(n,1); 

        for(int i = 1; i < n; i++){
            int c = pairs[i][0]; 
            for(int j = 0; j < i; j++){
                int b = pairs[j][1]; 
                if(b < c){
                    dp[i] = dp[j] + 1; 
                }
            }
        }

        return *max_element(dp.begin(),dp.end()); 
    }
};