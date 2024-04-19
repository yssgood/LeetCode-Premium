class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 == str2) return str1; 
        
        string divide = str1, divideby = str2; 
        if(str1.length() < str2.length()){
            divide = str2;
            divideby = str1; 
        }
        
        //cout << divide.substr(0,divideby.length()) << endl; 
        //cout << divideby << endl; 
        
        if(divide.substr(0,divideby.length()) == divideby) return divide.substr(divideby.length()); 
        
        return ""; 
    }
};