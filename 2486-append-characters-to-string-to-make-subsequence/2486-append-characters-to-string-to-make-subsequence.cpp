class Solution {
public:
    int appendCharacters(string s, string t) {
        int end = 0; 
        int start = 0; 
        while(end < s.length()){
            if(s[end] == t[start]){
                start++; 
            }
            end++; 
        }

        //cout << start; 
        return t.length() - start; 
    }
};