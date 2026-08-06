class Solution {
    public int pivotIndex(int[] nums) {
        int index = Integer.MAX_VALUE; 
        int[] prefix = new int[nums.length]; 

        for(int i = 1; i < nums.length; i++){
            prefix[i] = prefix[i-1] + nums[i-1]; 
        }

        int suffix = 0; 

        for(int i = nums.length-1; i >= 0; i--){
            if(prefix[i] == suffix) index = Math.min(index, i); 
            suffix += nums[i]; 
        }

        return index == Integer.MAX_VALUE ? -1 : index; 
    }
}