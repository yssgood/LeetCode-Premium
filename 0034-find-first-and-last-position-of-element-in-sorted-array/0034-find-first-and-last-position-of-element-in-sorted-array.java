class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0, right = nums.length-1; 
        int[] answer = new int[]{-1,-1}; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    answer[0] = mid; 
                }
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }

        left = 0; 
        right = nums.length-1; 

        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(nums[mid] <= target){
                if(nums[mid] == target){
                    answer[1] = mid; 
                }
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }


        return answer; 
    }
}