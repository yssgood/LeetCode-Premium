class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0; 
        int answer = 0; 
        int pointer = 0; 
        int low = prices[0], high = prices[0]; 
        while(pointer < prices.size()-1){

            while(pointer < prices.size()-1 && prices[pointer] >= prices[pointer+1]) pointer++; 
            low = prices[pointer]; 
            while(pointer < prices.size()-1 && prices[pointer] <= prices[pointer+1]) pointer++; 
            high = prices[pointer];
            answer += high - low; 
            pointer++; 
        }

        return answer; 
    }
};