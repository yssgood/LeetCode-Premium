class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        if(questions.size() <= 1) return (long long) questions[0][0]; 
        int n = questions.size(); 
        vector<long long> dp(n+1,0);

        for(int i = n - 1; i >= 0; i--){
            int point = questions[i][0], brainpower = questions[i][1]; 
            int index = i + brainpower >= n ? -1 : i + brainpower + 1;  
            long long take = point; 
            if(index != -1){
                take += dp[index]; 
            }

            long long skip = dp[i + 1]; 
            dp[i] = max(take, skip);
        }

        //for(auto n : dp) cout << n << ' '; 

        return dp[0];
    }
};