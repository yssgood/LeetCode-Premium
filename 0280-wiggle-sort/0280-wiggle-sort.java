class Solution {
    public void wiggleSort(int[] nums) {
        //1 2 3 4 5 6 
        //1 3 2 5 4 6

        Arrays.sort(nums); 
        for(int i = 2; i < nums.length; i+=2){
            int tmp = nums[i-1]; 
            nums[i-1] = nums[i]; 
            nums[i] = tmp; 
        }
    }


}