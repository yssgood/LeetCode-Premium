class Solution {
    public void wiggleSort(int[] nums) {
        //3 5 2 6 1 4 

        for(int i = 1; i < nums.length; i+=2){
            if(i + 1 < nums.length && nums[i] < nums[i+1]){
                int tmp = nums[i]; 
                nums[i] = nums[i+1]; 
                nums[i+1] = tmp; 
            }
        }

        for(int i = 0; i < nums.length; i+=2){
            if(i + 1 < nums.length && nums[i] > nums[i+1]){
                int tmp = nums[i]; 
                nums[i] = nums[i+1]; 
                nums[i+1] = tmp; 
            }
        }
    }


}