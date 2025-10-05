class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0; 
        int maxJump = 0; 
        int prevJump = 0; 
        int jump = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            maxJump = max(maxJump, nums[i] + i); 
            if(i == prevJump){
                jump++; 
                prevJump = maxJump; 
            }
        }
        return jump; 
    }
};