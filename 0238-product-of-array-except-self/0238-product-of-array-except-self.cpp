class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            answer[i] = nums[i-1] * answer[i-1]; 
        }

        int suffix = 1; 
        for(int i = nums.size()-1; i >= 0; i--){
            answer[i] *= suffix; 
            suffix *= nums[i]; 
        }


        return answer; 
    }
};