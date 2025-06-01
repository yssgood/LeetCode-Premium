class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //number of possible combinations, which means we need to memorize some state at some point 
        //the numbers are distinct, which means it does not work like a combination 

        //as long as i can have best number that adds up to the target
        
        //1 2 3 target = 4 
        int n = nums.size(); 
        vector<unsigned long long> dp(target+1,0); 

        dp[0] = 1; 

        for(int i = 1; i <= target; i++){
            for(int j = 0; j < n; j++){
                //dp[i] = dp[i-1]; 
                if(i >= nums[j]){
                    dp[i] += dp[i - nums[j]]; 
                }
            }
        }
        
        return (int)dp[target]; 
    }
};