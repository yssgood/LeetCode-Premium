class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0; 
        int currSum = 0; 
        int answer = INT_MAX; 
        while(end < nums.size()){
            //요구 사항 
            currSum += nums[end]; 



            //범위 확인 
            while(currSum >= target){
                answer = min(answer, end - start + 1);
                currSum -= nums[start];
                start++; 
            }



            //범위 증가 + 최소/최장 계산 (변경 가능) 
            end++; 
        }

        return answer == INT_MAX ? 0 : answer; 
    }
};