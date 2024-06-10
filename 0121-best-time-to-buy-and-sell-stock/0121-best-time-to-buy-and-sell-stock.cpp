class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; 
        int max_profit = 0; 
        for(int i = 0; i < prices.size(); i++){
            min_price = min(prices[i], min_price); 
            max_profit = max(prices[i] - min_price, max_profit); 
        }
        return max_profit; 
    }
};