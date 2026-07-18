class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length-1; 
        while(left < right){
            int mid = left + (right - left) / 2; 

            if(nums[mid] > nums[nums.length-1]){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }

        //System.out.print(left + " " + right); 

        if(nums[nums.length-1] >= target){
            right = nums.length-1; 
        } else{
            right = left; 
            left = 0; 
        }



        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(nums[mid] == target) return mid; 

            if(nums[mid] > target){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }



        return -1; 
    }
}