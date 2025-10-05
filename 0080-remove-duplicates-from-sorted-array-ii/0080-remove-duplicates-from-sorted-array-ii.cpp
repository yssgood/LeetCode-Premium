class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int p1 = 2; 
        for(int i = 2; i < nums.size(); i++){
            if(nums[p1-2] == nums[i]) continue; 
            nums[p1++] = nums[i]; 
        }
        return p1; 
    }
};