class Solution {
    public int pivotIndex(int[] nums) {
        int[] suffix = new int[nums.length]; 
        int rightMost = 0; 
        for(int i = nums.length-1; i >= 0; i--){
            suffix[i] += rightMost + nums[i];
            rightMost += nums[i]; 
        }
        int leftMost = 0; 
        for(int i = 0; i < nums.length-1; i++){
            int compare = suffix[i+1]; 
            if(leftMost == compare) return i; 
            leftMost += nums[i]; 
        }

        //System.out.print(leftMost); 
        if(leftMost == 0) return nums.length-1; 

        return -1; 
    }
}