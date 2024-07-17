class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 1; i < s.length(); i++){
            int prevNum = s[i-1] - '0'; 
            int currNum = s[i] - '0'; 
            bool flag = ((prevNum % 2 == 0 && currNum % 2 == 0) || (prevNum % 2 == 1 && currNum % 2 == 1)); 
            if(flag && prevNum > currNum){
                swap(s[i-1],s[i]);
                return s; 
            }
        }
        return s; 
    }
};