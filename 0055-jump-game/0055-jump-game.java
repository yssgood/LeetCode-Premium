class Solution {
    public boolean canJump(int[] nums) {
        int needJump = nums.length-1; 

        for(int i = nums.length-1; i >= 0; i--){
            if(i + nums[i] >= needJump){
                needJump = i; 
            } 
            
        }

        //2 3 1 1 4 
        //0  1  2  3  4

        //3 2 1 0 4 
        //4 4 4 4 0
        return needJump > 0 ? false : true; 
    }
}