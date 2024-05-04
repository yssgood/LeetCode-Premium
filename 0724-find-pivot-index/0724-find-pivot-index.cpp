class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size()+1, 0); 
        vector<int> suffix(nums.size()+1, 0); 

        for(int i = 1; i <= nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i-1]; 
        }

        for(int i = nums.size()-1; i >= 0; i--){
            suffix[i] = suffix[i+1] + nums[i];
        }  

        for(int i = 0; i < prefix.size()-1; i++){
            if(prefix[i] == suffix[i+1]) return i; 
        }

        return -1; 
    }
};