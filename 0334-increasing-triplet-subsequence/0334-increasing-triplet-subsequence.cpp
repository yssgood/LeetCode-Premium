class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int choice1 = INT_MAX, choice2 = INT_MAX; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= choice1) choice1 = nums[i]; 
            else if(nums[i] <= choice2) choice2 = nums[i]; 
            else return true; 
        }
        return false; 
    }
};