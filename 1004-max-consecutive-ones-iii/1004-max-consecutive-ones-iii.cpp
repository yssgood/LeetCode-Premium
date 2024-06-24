class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0; 
        int start = 0, end = 0; 
        while(end < nums.size()){
            k -= nums[end] == 0 ? 1 : 0; 

            while(k < 0){
                //answer = max(answer, end - start + 1); 
                k += nums[start] == 0 ? 1 : 0; 
                start++; 
            }
            answer = max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
};