class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int index = -1; 

        for(int i = 0; i < nums.length; i++){
            if(nums[i] == 1){
                if(index == -1){
                    index = i; 
                } else{
                    if(i - index - 1 < k) return false; 
                    index = i; 
                }
            }
        }
        return true; 
    }
}