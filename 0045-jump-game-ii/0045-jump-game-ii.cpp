class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0; 
        int maxJump = 0; 
        int currEnd = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            maxJump = max(maxJump, nums[i] + i);
            if(i == currEnd){
                jumps++; 
                currEnd = maxJump; 
            }
        }
        return jumps; 
    }
};