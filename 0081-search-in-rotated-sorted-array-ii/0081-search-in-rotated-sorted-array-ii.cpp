class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 

        while(left < right){
            while(left < right && nums[left] == nums[left+1]) left++; 
            while(left < right && nums[right] == nums[right-1]) right--; 

            cout << left << ' ' << right << endl; 

            int mid = (right + left) / 2; 

            if(nums[mid] > nums[right]){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }

        if(target > nums[nums.size()-1]){
            right = left; 
            left = 0; 
        } else{
            right = nums.size()-1; 
        }

        while(left <= right){
            int mid = (right + left) / 2; 

            if(nums[mid] == target) return true; 

            if(nums[mid] < target){
                left = mid + 1; 
            } else{
                right = mid -1; 
            }
        }

        cout << left; 
        return false; 
    }
};