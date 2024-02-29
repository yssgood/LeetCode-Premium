class Solution {
public:
    int reverse(int x) {
        long answer = 0;
        long temp = 0;
        bool negative = false; 
        if (x<0){
            negative = true; 
        }
        while (x>0){
            answer = (answer*10) + (x%10);
            x = x/10;
        }
        if (negative){
            temp = long(x); 
            temp = -1 * temp; 
            while (temp>0){
                answer = (answer*10) + (temp%10);
                temp = temp/10;
            }
            answer = -1 * answer; 
        }
        if (answer > INT_MAX || answer < INT_MIN){
            return 0;
        }
        
        return answer;
    }
};