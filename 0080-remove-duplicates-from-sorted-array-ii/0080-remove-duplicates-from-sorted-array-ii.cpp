class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(index > 1 && nums[i] == nums[index-1] && nums[index-2] == nums[index-1]) continue; 
            nums[index++] = nums[i]; 
        }
        return index; 
    }
};