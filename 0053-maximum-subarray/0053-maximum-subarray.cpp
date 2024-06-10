class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 

        int curr_sum = nums[0]; 
        int curr_head = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            curr_head += nums[i];
            curr_sum = max(curr_sum, max(curr_head, nums[i])); 
            curr_head = max(curr_head, nums[i]); 
        }

        return curr_sum; 
    }
};