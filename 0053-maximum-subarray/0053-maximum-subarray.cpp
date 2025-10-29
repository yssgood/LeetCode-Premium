class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0]; 
        int curr_sum = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            int includeSum = nums[i] + curr_sum; 
            max_sum = max(max_sum, max(includeSum, nums[i])); 
            curr_sum = max(includeSum, nums[i]); 
        }
        return max_sum; 
    }
};