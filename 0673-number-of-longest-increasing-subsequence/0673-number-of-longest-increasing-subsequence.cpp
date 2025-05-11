class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return 1; 
        int n = nums.size(); 
        vector<int> dp(n,1); 
        vector<int> count(n,1); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1; 
                        count[i] = count[j]; 
                    } else if(dp[j] + 1 == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
        }

        int longest = *max_element(dp.begin(), dp.end()); 
        int answer = 0; 
        for(int i = 0; i < n; i++){
            if(dp[i] == longest) answer += count[i]; 
        }
        return answer; 
    }
};