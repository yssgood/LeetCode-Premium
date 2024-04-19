class Solution {
public:
    string reverseVowels(string s) {
        int start = 0, end = s.length()-1; 
        map<char,int> hashMap = {{'a',1}, {'e',1}, {'o',1}, {'u',1}, {'i',1}}; 
        while(start < end){
            bool a = hashMap.count(tolower(s[start])); 
            bool b = hashMap.count(tolower(s[end]));

            if(a && b){
                swap(s[start], s[end]); 
                start++; 
                end--; 
            } else if(!a && !b){
                start++;
                end--; 
            } else if(a && !b){
                end--;  
            } else{
                start++; 
            }

        }
        return s; 
    }
};