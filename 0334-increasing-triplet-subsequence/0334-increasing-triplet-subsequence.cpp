class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX; 
        int second =  INT_MAX; 
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i]; 
            if(first >= curr){
                first = curr; 
            } else if(second >= curr){
                second = curr; 
            } else{
                return true; 
            }
        }

        return false; 
    }
};