class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> memo(n,-1); 
        return helper(memo,nums,n-1); 
    }

    int helper(vector<int>& memo, vector<int>& nums, int index){
        if(index == 0) return nums[0]; 
        if(index == 1) return max(nums[0],nums[1]); 

        if(memo[index] != -1) return memo[index]; 

        int choice1 = helper(memo,nums,index-2) + nums[index]; 
        int choice2 = helper(memo,nums,index-1); 
        memo[index] = max(choice1,choice2);
        return memo[index]; 
    }
};