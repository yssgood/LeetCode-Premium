class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0; 
        int left = numBottles; 
        while(left >= numExchange){
            answer += (left / numExchange); 
            left = (left / numExchange) + (left % numExchange); 
        }
        return answer + numBottles; 
    }
};