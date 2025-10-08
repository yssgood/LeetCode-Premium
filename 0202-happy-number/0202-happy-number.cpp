class Solution {
public:
    bool isHappy(int n) {
        int number = n; 
        unordered_map<int,int> hashMap; 
        while(number != 1){
            int happy = getNumber(number); 
            if(hashMap.count(happy)) return false; 

            hashMap[happy]++; 
            number = happy; 
        }
        return true; 
    }

    int getNumber(int number){
        int res = 0; 
        while(number){
            int lastDigit = number % 10; 
            res += lastDigit * lastDigit; 
            number /= 10; 
        }
        return res; 
    }
};