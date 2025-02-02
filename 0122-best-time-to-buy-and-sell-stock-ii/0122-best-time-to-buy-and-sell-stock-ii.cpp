class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0; 
        int bestPrice = prices[0]; 
        for(int i = 1; i < prices.size(); i++){
            int curr = prices[i]; 
            if(curr - bestPrice > 0){
                answer += (curr - bestPrice); 
                bestPrice = INT_MAX; 
            }
            bestPrice = min(bestPrice, curr); 
        }
        return answer; 
    }
};