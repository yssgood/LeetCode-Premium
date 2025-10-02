class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, answer = INT_MAX;  
        while(end < nums.size()){
            target -= nums[end]; 

            while(target <= 0){
                answer = min(answer, end - start + 1); 
                target += nums[start++]; 
            }

            end++; 
        }

        return answer == INT_MAX ? 0 : answer; 
    }
};