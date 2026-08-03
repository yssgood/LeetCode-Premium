class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1; 
        int right = Integer.MIN_VALUE; 
        for(int p : piles){
            right = Math.max(right,p); 
        }

        int answer = 0; 
        while(left <= right){
            int k = left + (right - left) / 2; 

            long time = 0; 
            for(int n : piles){
                time += (n / k); 
                time += (n % k > 0 ? 1 : 0); 
            }

            if(time <= h){
                answer = k; 
                right = k - 1; 
            } else{
                left = k + 1; 
            }
        }

        return answer; 
    }
}