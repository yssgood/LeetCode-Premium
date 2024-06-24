class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); 
        int left = 0, right = nums.size()-1; 
        int answer = 0; 
        while(left < right){
            int sum = nums[left] + nums[right]; 

            if(sum > k){
                right--; 
            } else if(sum < k){
                left++; 
            } else{
                left++;
                right--;
                answer++; 
            }
        }
        return answer; 
    }
};