class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0]; 
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum += nums[i]; 
            curr_max = max(curr_max, max(sum, nums[i]));
            sum = max(sum, nums[i]); 
        }
        return curr_max;
    }
};