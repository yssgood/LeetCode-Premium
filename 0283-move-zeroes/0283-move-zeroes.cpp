class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0; 
        while(end < nums.size()){

            if(nums[end] != 0){
                int tmp = nums[start]; 
                nums[start] = nums[end]; 
                nums[end] = tmp; 
                start++; 
            }
            end++; 
        }
    }
};