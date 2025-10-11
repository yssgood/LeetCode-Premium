class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0; 
        
        int jump = 0; 
        int currEnd = 0; 
        int maxJump = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            maxJump = max(maxJump, i + nums[i]); 
            if(i == currEnd){
                jump++; 
                currEnd = maxJump; 
            }
        }
        return jump; 
    }
};