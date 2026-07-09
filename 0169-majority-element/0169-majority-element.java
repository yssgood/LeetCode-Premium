class Solution {
    public int majorityElement(int[] nums) {
        int lastNum = -1; 
        int count = 0; 

        for(int i = 0; i < nums.length; i++){
            if(nums[i] != lastNum){
                count--; 
                if(count < 0){
                    lastNum = nums[i]; 
                    count = 0; 
                }
            } else{
                count++; 
            }
        }

        return lastNum; 
    }
}