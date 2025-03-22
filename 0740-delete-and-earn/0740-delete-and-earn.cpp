class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0]; 

        int max_ele = *max_element(nums.begin(),nums.end()); 
        vector<int> dp(max_ele + 1, 0); 
        map<int,int> hashMap; 
        for(int n : nums) hashMap[n] += n; 

        //3 1 
        dp[1] = hashMap[1]; 

        for(int i = 2; i <= max_ele; i++){
            dp[i] = max(dp[i - 2] + hashMap[i], dp[i-1]);
        }
        
        return dp[max_ele]; 
    }
};