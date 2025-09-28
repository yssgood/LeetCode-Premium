class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1); 
        //1 2 3 4 
        //1 1 2 6
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }
        int suffix = nums[nums.size()-1]; 
        for(int i = nums.size()-2; i >= 0; i--){
            prefix[i] *= suffix; 
            suffix *= nums[i]; 
        }
        return prefix; 
    }
};