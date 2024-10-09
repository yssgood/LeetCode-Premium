class Solution {
public:
    string reverseVowels(string s) {
        set<char> hashSet = {'a','e','i','o','u','A','E','I','O','U'}; 
        int start = 0, end = s.length()-1; 
        while(start < end){
            char a = tolower(s[start]);
            char b = tolower(s[end]);

            while(start < end && !hashSet.count(s[start])) start++;
            while(start < end && !hashSet.count(s[end])) end--; 


            swap(s[start], s[end]);
            start++;
            end--; 
        }

        return s; 
    }
};