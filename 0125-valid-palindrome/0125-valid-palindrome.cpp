class Solution {
public:
    bool isPalindrome(string s) {
        string convert = ""; 

        for(char& c : s){
            
            if(isalpha(c) || isdigit(c)){
                c = isupper(c) ? tolower(c) : c; 
                convert += c; 
            }
        }

        //cout << convert << ' '; 
        string copy = convert; 
        reverse(copy.begin(), copy.end()); 

        return convert == copy; 
    }
};