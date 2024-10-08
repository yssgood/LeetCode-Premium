class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0, end = 0;
        while(end < haystack.length()){
            
            if(end - start + 1 >= needle.length()){
                string tmp = haystack.substr(start, end - start + 1);
                if(tmp == needle) return start; 
                start++; 
            }

            end++; 
        }

        return -1; 
    }
};