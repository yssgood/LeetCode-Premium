class Solution {
    public int absDifference(int[] nums, int k) {
        Arrays.sort(nums); 
        int[] prefix = new int[nums.length+1]; 
        for(int i = 1; i <= nums.length; i++){
            prefix[i] = prefix[i-1] + nums[i-1]; 
        }

        
        int n = nums.length; 
        

        return Math.abs((prefix[n] - prefix[n-k]) - prefix[k]);
    }
}