class Solution {
public:
    int romanToInt(string s) {
        map<char,int> hashMap = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M', 1000}}; 
        int answer = 0;  

        for(int i = 0; i < s.length(); i++){
            int first = hashMap[s[i]]; 
            int second = i < s.length()-1 ? hashMap[s[i+1]] : INT_MIN; 
            if(first < second){
                answer += second - first; 
                i++; 
            } else{
                answer += first; 
            }
        }

        return answer; 
    }
};