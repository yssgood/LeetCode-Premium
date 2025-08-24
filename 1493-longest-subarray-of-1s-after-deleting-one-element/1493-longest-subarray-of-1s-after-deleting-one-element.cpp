class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, end = 0; 
        int answer = 0; 
        int k = 1; 
        while(end < nums.size()){
            k -= (nums[end] == 0) ? 1 : 0; 
            while(k < 0){
                //answer = max(answer, end - start); 
                k += (nums[start] == 0) ? 1 : 0; 
                start++; 
            }
            answer = max(answer, end - start); 
            end++; 

        }
        return answer; 
    }
};