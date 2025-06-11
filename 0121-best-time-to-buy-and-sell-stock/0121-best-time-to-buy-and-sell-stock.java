class Solution {
    public int maxProfit(int[] prices) {
        int max_ = 0; 
        int min_ = prices[0];
        for(int i = 1; i < prices.length; i++){
            max_ = Math.max(max_, prices[i] - min_); 
            min_ = Math.min(min_, prices[i]); 
        }
        return max_; 
    }
}