class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 0; 
        while(end < nums.size()){
            while(start < nums.size() && nums[start] != 0){
                start++; 
            }

            if(nums[end] != 0 && end > start){
                //cout << start << ' '; 
                int tmp = nums[start]; 
                nums[start] = nums[end];
                nums[end] = tmp; 
                //start = end; 
            }

            end++; 
        }
    }
};