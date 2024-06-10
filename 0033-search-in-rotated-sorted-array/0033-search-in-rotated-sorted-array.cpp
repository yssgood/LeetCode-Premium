class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 
        int pivot = 0; 

        while(left < right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target) return mid; 
            
            if(nums[mid] > nums[right]){
                left = mid + 1; 
                pivot = left; 
            } else{
                right = mid; 
            }
        }
        
        if(target <= nums[nums.size()-1]){
            left = pivot; 
            right = nums.size()-1; 
        } else{
            left = 0; 
            right = pivot; 
        }
        
        while(left <= right){
            int mid = (right + left) / 2; 
            
            if(nums[mid] == target) return mid; 

            if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }
        return -1; 
    }
};