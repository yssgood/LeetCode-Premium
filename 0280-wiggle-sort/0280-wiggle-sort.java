class Solution {
    public void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp; 
    }
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums); 
        for(int i = 1; i < nums.length-1; i += 2){
            swap(nums,i,i+1); 
        }

        //1 2 3 4 5 6 
        //1 3 2 5 4 6
    }
}