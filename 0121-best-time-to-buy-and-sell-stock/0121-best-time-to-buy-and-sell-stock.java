class Solution {
    public int maxProfit(int[] prices) {
        int currMin = prices[0]; 
        int answer = 0; 
        for(int i = 1; i < prices.length; i++){
            answer = Math.max(answer, prices[i] - currMin); 
            currMin = Math.min(currMin, prices[i]); 
        }
        return answer; 
    }
}