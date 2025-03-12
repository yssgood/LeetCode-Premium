class Solution {
    public int maximumCount(int[] nums) {
        int left = 0, right = nums.length; 
        while(left < right){
            int mid = (right + left) / 2; 
            if(nums[mid] < 0){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }
        int neg = Math.max(0,left); 
        right = nums.length; 
        while(left < right){
            int mid = (right + left) / 2; 
            if(nums[mid] < 1){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }
        int pos = left; 
        return Math.max(neg, nums.length - pos); 
    }
}