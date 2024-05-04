class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = INT_MIN; 
        int start = 0, end = 0; 
        int flip = 1; 
        while(end < nums.size()){
            if(nums[end] == 0 && flip <= 0){
                while(start < nums.size() && flip <= 0){
                    flip += nums[start] == 0 ? 1 : 0; 
                    start++; 
                }
            }

            flip -= nums[end] == 0 ? 1 : 0; 
            answer = max(answer, end - start + 1); 
            end++; 
        }

        return answer; 
    }
};