class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int length = nums.size() / 2; 
        int left = 0, right = nums.size()-1; 
        int leftPivot = -1; 
        
        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                leftPivot = mid; 
                right = mid - 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }


        int rightPivot = -1; 
        left = 0; 
        right = nums.size()-1; 
        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target){
                rightPivot = mid; 
                left = mid + 1; 
            } else if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }

        //cout << leftPivot << ' ' << rightPivot << ' ' << length; 

        if(leftPivot == -1 || rightPivot == -1) return false; 

        return rightPivot - leftPivot + 1 > length; 
    }
};