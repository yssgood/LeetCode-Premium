class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums); 
        int count = 0; 
        for(int n : nums){
            if(n != count) return count; 
            count++; 
        }
        return count; 
    }
}