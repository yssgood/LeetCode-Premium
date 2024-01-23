class Solution {
    public int findDuplicate(int[] nums) {
        int left = 1; 
        int high = 0; 
        int duplicate = -1; 
        for(int n : nums) high = Math.max(n,high); 

        while(left < high){
            int mid = left + (high - left) / 2; 
            int cnt = 0; 

            for(int n : nums){
                if(n <= mid) cnt++; 
            }

            if(cnt > mid){
                duplicate = mid; 
                high = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }

        return duplicate; 
    }
}