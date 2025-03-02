class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() <= 1) return nums[0]; 
        vector<int> dp(20001,0); //최대 값만 저장 
        map<int,int> hashMap; 
        int max_ = 0; 
        for(int n : nums){
            hashMap[n] += n; 
            max_ = max(max_, n); 
        }

        dp[0] = 0; 
        dp[1] = hashMap[1]; 
        for(int i = 2; i <= max_; i++){
            dp[i] = max(dp[i-1], dp[i-2] + hashMap[i]); 
        }

        return dp[max_]; 
    }
};

//1 = 3
//2 = 3
//3 = 3
//4 = 4
//5 = 15
//6 = 15 