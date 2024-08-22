class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1; 
        while(start < end){
            while(start < end && !isalnum(s[start])) start++; 
            while(start < end && !isalnum(s[end])) end--; 

            char tmpA = tolower(s[start]); 
            char tmpB = tolower(s[end]); 

            //cout << tmpA << ' ' << tmpB; 
            if(tmpA != tmpB) return false; 

            start++;
            end--; 
        }
        return true; 
    }
};