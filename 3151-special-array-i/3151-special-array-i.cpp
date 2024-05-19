class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() < 2) return true; 
        for(int i = 1; i < nums.size(); i++){
            bool flag1 = nums[i-1] % 2; 
            bool flag2 = nums[i] % 2; 
            
            if(flag1 == flag2) return false; 
        }
        
        return true;
    }
};