class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()); 
        vector<int> suffix(nums.size()); 
        vector<int> answer(nums.size(),0); 
        prefix[0] = 1 * nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i]; 
        }

        suffix[suffix.size()-1] = 1 * nums[nums.size()-1]; 
        for(int i = nums.size()-2; i >= 0; i--){
            suffix[i] = suffix[i+1] * nums[i]; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                answer[i] = suffix[i+1]; 
            } else if(i == nums.size()-1){
                answer[i] = prefix[i-1]; 
            } else{
                answer[i] = prefix[i-1] * suffix[i+1]; 
            }
        }

        return answer; 
    }
};