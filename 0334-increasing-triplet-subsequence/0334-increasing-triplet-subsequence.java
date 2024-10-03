class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE; 
        int second = Integer.MAX_VALUE; 

        for(int i = 0; i < nums.length; i++){
            int curr = nums[i]; 

            if(first >= curr){
                first = curr; 
            } else if(second >= curr){
                second = curr; 
            } else{
                return true; 
            }
        }


        return false; 
    }
}