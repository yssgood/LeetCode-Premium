class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0; 
        int answer = 0; 
        int start = 0, end = 0; 

        while(end < nums.size()){
            if(nums[end] == 0){
                count++; 
            }

            while(count > 1){
                if(nums[start] == 0) count--; 
                start++; 
            }

            answer = max(answer, end - start); 
            end++; 
        }

        return answer; 
    }
};