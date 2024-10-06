class Solution {
    public int removeElement(int[] nums, int val) {
        int start = 0, end = nums.length-1;  
        for(int i = end; i >= 0; i--){
            if(nums[i] != val){
                end = i; 
                break;  
            }
        }

        //System.out.println(end); 

        while(start < end){
            if(nums[start] == val){
                int tmp = nums[start]; 
                nums[start] = nums[end]; 
                nums[end] = tmp; 
                //start++;
                end--; 
            }
            start++; 
        }

        //System.out.print(Arrays.toString(nums)); 

        return start + 1;  
    }
}