class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size() / 2; 
        int left = 0, right = nums.size()-1; 
        int pivot = -1; 
        int pivot2 = -1; 
        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                pivot = mid; 
                right = mid - 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }

        }
        
        left = 0; 
        right = nums.size()-1; 
        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                pivot2 = mid; 
                left = mid + 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid -1; 
            }
        }
        //cout << pivot2 << ' ' << pivot; 
        if(pivot == -1 || pivot2 == -1) return false; 
        return pivot2 - pivot + 1 > n; 
    }
};