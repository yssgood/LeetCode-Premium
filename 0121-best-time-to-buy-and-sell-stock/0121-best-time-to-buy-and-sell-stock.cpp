class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0; 
        int curr_min = prices[0]; 
        for(int i = 1; i < prices.size(); i++){
            answer = max(answer, prices[i] - curr_min); 
            curr_min = min(curr_min, prices[i]); 
        }
        return answer; 
    }
};