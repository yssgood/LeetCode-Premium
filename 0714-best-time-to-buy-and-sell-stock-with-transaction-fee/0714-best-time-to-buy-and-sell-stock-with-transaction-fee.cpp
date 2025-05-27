class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0; 

        int n = prices.size(); 

        vector<int> hold(n), sold(n);

        hold[0] = -prices[0]; 
        sold[0] = 0; 

        for(int i = 1; i < prices.size(); i++){
            hold[i] = max(hold[i-1], sold[i-1] - prices[i]); 
            sold[i] = max(sold[i-1], hold[i-1] + prices[i] - fee); 
        }

        return sold[prices.size()-1]; 
    }
};