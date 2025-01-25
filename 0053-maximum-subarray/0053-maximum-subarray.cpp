class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0]; 
        int currSum = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            int includedSum = currSum + nums[i]; 
            max_sum = max(max_sum, max(includedSum,nums[i])); 
            currSum = max(includedSum, nums[i]); 
        }

        return max_sum; 
    }
};