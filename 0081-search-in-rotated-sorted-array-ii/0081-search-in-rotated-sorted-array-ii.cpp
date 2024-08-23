class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 

        while(left <= right){
            while(left < right && nums[left] == nums[left+1]) left++; 
            while(left < right && nums[right] == nums[right-1]) right--; 
            int mid = (right + left) / 2; 

            if(nums[mid] == target) return true; 

            if(nums[mid] > target){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }

        }
        return false; 
    }
};