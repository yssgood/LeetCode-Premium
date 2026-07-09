class Solution {
    public int maxProfit(int[] prices) {
        int maxPrice = 0; 
        int currPrice = prices[0]; 
        for(int i = 1; i < prices.length; i++){
            maxPrice = Math.max(maxPrice, prices[i] - currPrice); 
            currPrice = Math.min(currPrice, prices[i]); 
        }
        return maxPrice; 
    }
}