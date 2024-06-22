class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0; 
        int currMax = 0; 
        int answer = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            int currJump = nums[i]; 

            if(i == currMax){
                answer++; 
                currMax = currMax + currJump; 
                //need to jump again 
            } else if(i + currJump > currMax){
                currMax = i + currJump; 
                answer++; 
            }
        }
        return answer; 
    }
};