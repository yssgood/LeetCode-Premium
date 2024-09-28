class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0; 
        int currMin = prices[0]; 
        for(int i = 1; i < prices.size(); i++){
            answer = max(answer, prices[i] - currMin); 
            currMin = min(currMin, prices[i]); 
        }

        return answer; 
    }
};