class Solution {
public:
    int romanToInt(string s) {
        map<char,int> hashMap = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D', 500}, {'M',1000}}; 
        int answer = 0; 
        for(int i = 0; i < s.length(); i++){
            if(i + 1 < s.length() && hashMap[s[i]] < hashMap[s[i+1]]){
                answer += hashMap[s[i+1]] - hashMap[s[i]]; 
                i++; 
            } else{
                answer += hashMap[s[i]]; 
            }
        }
        return answer; 
    }
};