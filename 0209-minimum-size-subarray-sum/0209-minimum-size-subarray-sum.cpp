class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, tmp = 0, answer = INT_MAX; 
        while(end < nums.size()){
            tmp += nums[end]; 
            while(tmp >= target){
                answer = min(answer, end - start + 1); 
                tmp -= nums[start];
                start++; 
            }
            end++; 
        }
        return answer == INT_MAX ? 0 : answer; 
    }
};