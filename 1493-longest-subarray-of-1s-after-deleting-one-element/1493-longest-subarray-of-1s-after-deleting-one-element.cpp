class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int answer = 0;   
        int start = 0, end = 0; 
        int remove = 0; 
        while(end < nums.size()){
            if(nums[end] == 0){
                remove++; 
            }
            while(remove > 1){
                remove -= nums[start] == 0 ? 1 : 0;
                start++; 
            }
            answer = max(answer, end - start + 1); 
            end++; 
        }
        return answer - 1; 
    }
};