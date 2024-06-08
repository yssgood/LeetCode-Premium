class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1); 
        vector<int> suffix(nums.size() + 1); 
        prefix[0] = 1;  
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }
        suffix[suffix.size()-1] = 1; 
        for(int i = nums.size()-1; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i+1]; 
        }
        vector<int> answer(nums.size(),0); 
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                answer[i] = suffix[i+1]; 
            } 
            if(i == nums.size()-1){
                answer[i] = prefix[i]; 
            } else{
                answer[i] = prefix[i] * suffix[i+1]; 
            }
        }

        return answer; 
    }
};