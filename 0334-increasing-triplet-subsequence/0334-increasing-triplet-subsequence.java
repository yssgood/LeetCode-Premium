class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first = nums[0]; 
        int second = Integer.MAX_VALUE; 
        int third = Integer.MAX_VALUE; 
        for(int i = 1; i < nums.length; i++){
            if(nums[i] <= first){
                first = nums[i]; 
            } else if(nums[i] <= second){
                second = nums[i]; 
            } else{
                return true; 
            }
        }

        return false; 
    }
}