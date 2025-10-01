class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0;  
        while(numBottles >= numExchange){
            answer += numExchange; 
            numBottles -= numExchange; 

            numBottles++; 
        }
        return answer + numBottles; 
    }
};