class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int missing = 0; 
        int num = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            //missing += (nums[i] - num) - 1; 
            int add = (nums[i] - num) - 1; 
            if(add >= k){
                return num + k; 
            }
            num = nums[i]; 
            k -= add; 
        }
        return nums[nums.size()-1] + k; 
    }
};