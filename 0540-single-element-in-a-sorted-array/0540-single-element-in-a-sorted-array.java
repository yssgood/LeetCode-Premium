class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length == 1) return nums[0];  
        int left  = 0, right = nums.length-1; 

        while(left < right){
            int mid = left + (right - left) / 2; 
            if(mid % 2 == 1 && nums[mid-1] == nums[mid] || mid % 2 == 0 && nums[mid+1] == nums[mid]){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }

        return nums[left]; 
    }
}