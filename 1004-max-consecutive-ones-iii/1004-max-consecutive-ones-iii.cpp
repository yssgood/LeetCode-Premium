class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = INT_MIN, curr_max = 0; 
        int start = 0, end = 0; 
        while(end < nums.size()){
            if(nums[end] == 0 && k <= 0){
                //move  
                while(start < nums.size() && k <= 0){
                    k += nums[start] == 0 ? 1 : 0; 
                    start++; 
                }
            } 
            k -= nums[end] == 0 ? 1 : 0; 
            curr_max = (end - start) + 1; 
            answer = max(answer, curr_max); 

            end++; 
        }

        return answer; 
    }
};