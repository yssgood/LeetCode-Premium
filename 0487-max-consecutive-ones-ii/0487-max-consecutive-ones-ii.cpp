class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0; 
        int start = 0, end = 0;
        int k = 1; 
        while(end < nums.size()){
            k -= nums[end] == 0 ? 1 : 0; 
            while(k < 0){
                k += nums[start] == 0 ? 1 : 0; 
                start++; 
            }
            answer = max(answer, end - start + 1);
            end++; 
        }   
        return answer; 
    }
};