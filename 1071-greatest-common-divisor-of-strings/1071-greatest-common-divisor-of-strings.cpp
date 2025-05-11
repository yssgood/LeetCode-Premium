class Solution {
public:
    bool findGCD(string& divide, string& s){
        if(divide.length() > s.length()) return false; 
        for(int i = 0; i < s.length(); i += divide.length()){
            string tmp = s.substr(i, divide.length()); 
            if(tmp != divide) return false; 
        }
        return true; 
    }
    string gcdOfStrings(string str1, string str2) {
        for(int i = str2.length(); i > 0; i--){
            string tmp = str2.substr(0,i);
            if(findGCD(tmp,str1) && findGCD(tmp,str2)) return tmp; 
        }
        return ""; 
    }
};