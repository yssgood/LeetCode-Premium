class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1, right = 0;
        for(int n : piles){
            right = Math.max(right, n); 
        }
        int candidate = 0; 
        
        while(left <= right){
            int k = left + (right - left) / 2; 

            //boolean leftOver = false; 
            long numRounds = 0; 
            for(int n : piles){
                numRounds += k > n ? 1 : n / k; 
                if(n > k && n % k > 0){
                    numRounds++; 
                    //System.out.println(n + " " + k); 
                    //leftOver = true; 
                }
            }

            //numRounds += leftOver ? 1 : 0; 

            //System.out.println(numRounds + " " + k + " " + leftOver);

            if(numRounds <= h){
                candidate = k; 
                right = k - 1; 
            }
            else left = k + 1; 
        }

        return candidate; 
    }
}