class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++){
            string tmp = haystack.substr(i,needle.length()); 
            if(tmp == needle) return i; 
        }
        return -1; 
    }
};