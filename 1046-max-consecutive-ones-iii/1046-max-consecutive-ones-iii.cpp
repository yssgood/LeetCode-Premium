class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0; 
        int start = 0, end = 0; 

        while(end < nums.size()){
            if(nums[end] == 0){
                k--; 
            }

            while(nums[end] == 0 && k < 0){
                if(nums[start] == 0) k++; 
                start++; 
            }

            answer = max(answer, end - start + 1);
            end++; 
        }
        return answer; 
    }
};