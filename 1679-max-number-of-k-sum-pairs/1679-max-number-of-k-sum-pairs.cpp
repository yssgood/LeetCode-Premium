class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0; 
        int end = nums.size()-1; 
        int answer = 0; 
        while(start < end){
            int sum = nums[start] + nums[end]; 
            if(sum > k){
                end--; 
            } else if(sum < k){
                start++; 
            } else{
                start++;
                end--; 
                answer++; 
            }
        }
        return answer; 
    }
};