class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0, end = 0, zeroCount = 0; 
        int answer = 0, zeroIndex = 0; 

        while(end < nums.size()){
            if(nums[end] == 0) zeroCount++; 
            
            while(zeroCount >= 2){
                if(nums[start++] == 0) zeroCount--; 
            }

            answer = max(answer, end - start + 1); 

            end++; 
        }

        return answer; 
    }
};