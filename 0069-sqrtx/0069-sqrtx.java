class Solution {
    public int mySqrt(int x) {
        if(x < 2) return x; 
        int left = 1, right = x; 
        int candidate = 0; 
        while(left <= right){
            int mid = left + (right - left) / 2; 
            long square = (long) mid * mid; 

            if(square <= x){
                candidate = mid; 
                left = mid + 1; 
            } else{
                right = mid - 1; 
            }
        }

        return candidate; 
    }
}