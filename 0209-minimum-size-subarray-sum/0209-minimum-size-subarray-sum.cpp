class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0; 
        int curr_sum = 0; 
        int answer = INT_MAX; 
        while(end < nums.size()){
            curr_sum += nums[end]; 
            
            while(curr_sum > target){
                answer = min(answer, end - start + 1);  
                curr_sum -= nums[start]; 
                start++; 
            }

            if(curr_sum >= target) answer = min(answer, end - start + 1);  
            end++; 
        }
        return answer == INT_MAX ? 0 : answer; 
    }
};