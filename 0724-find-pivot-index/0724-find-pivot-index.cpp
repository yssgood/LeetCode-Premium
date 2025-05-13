class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() <= 1) return 0; 
        int index = INT_MAX; 
        vector<int> answer(nums.size(),0);
        for(int i = 1; i < nums.size(); i++){
            answer[i] = answer[i-1] + nums[i-1]; 
        }

        int suffix = 0; 
        for(int i = nums.size()-1; i >= 0; i--){
            if(answer[i] == suffix) index = min(index,i); 
            suffix += nums[i]; 
        }

        return index == INT_MAX ? -1 : index; 
    }
};