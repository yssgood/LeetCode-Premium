class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return 1; 
        vector<int> dp(nums.size(),1); 
        int answer = 1; 
        for(int i = 1; i < nums.size(); i++){
            //cout << nums[i] << ' '; 
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    //cout << nums[i] << ' ' << nums[j] << endl; 
                    dp[i] = max(dp[i], dp[j] + 1); 
                    answer = max(answer, dp[i]); 
                }
            }
        }

        // for(int i = 0; i < dp.size(); i++){
        //     cout << dp[i] << ' '; 
        // }

        return answer; 
    }
};