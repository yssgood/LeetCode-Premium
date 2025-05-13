class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0; 
        int max_ = 0, count = 0; 
        while(end < nums.size()){
            count += nums[end] == 0 ? 1 : 0; 
            while(count > k){
                count -= nums[start] == 0 ? 1 : 0;
                start++;  
            }
            max_ = max(max_, end - start + 1); 
            end++; 
        }
        return max_; 
    }
};