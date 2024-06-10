class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_max_jump = 0; 
        int end_index = 0; 
        int answer = 0; 
        for(int i = 0; i < nums.size()-1; i++){
            curr_max_jump = max(curr_max_jump, i + nums[i]); 

            if(i == end_index){
                end_index = curr_max_jump; 
                answer++; 
            }
        }
        return answer; 
    }
};