class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long answer = 0;
        int start = 0, end = 0; 
        int prev = -1; 
        while(end < nums.size()){
            
            if(nums[end] == prev){
                start = end; 
            }
            prev = nums[end]; 
            answer += (end - start) + 1; 
            end++;
        }

        return answer; 
    }
};