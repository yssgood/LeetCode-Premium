class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1; 
        while(start < end){
            while(start < end && !isalnum(s[start])) start++;  
            while(start < end && !isalnum(s[end])) end--; 

            char a = tolower(s[start]);
            char b = tolower(s[end]); 

            if(a != b) return false; 
            start++;
            end--;  
        }
        return true; 
    }
};