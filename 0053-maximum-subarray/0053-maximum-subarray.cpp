class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0]; 
        int curr = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            curr_max = max(curr_max, max(curr + nums[i], nums[i])); 
            curr = max(curr + nums[i], nums[i]); 
        }
        return curr_max; 
    }
};