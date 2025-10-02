class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0; 
        int n = haystack.length(); 
        int m = needle.length(); 
        for(int i = 0; i <= n - m; i++){
            string compare = haystack.substr(i,m); 
            if(compare == needle) return i; 
        }
        return -1; 
    }
};