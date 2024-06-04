class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 

        while(left < right){
            int mid = (right + left) / 2; 

            if(nums[mid] > nums[right]){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }
        int pivot = left; 
        left = pivot; 
        right = nums.size()-1; 
        
        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                return mid; 
            }

            if(nums[mid] > target){
                right = mid -1; 
            } else{
                left = mid + 1; 
            }
        }

        left = 0;
        right = pivot; 

        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                return mid; 
            }

            if(nums[mid] > target){
                right = mid -1; 
            } else{
                left = mid + 1; 
            }
        }




        return -1; 
    }
};