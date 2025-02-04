class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> hashMap; 
        int min_index = 0, min_len = INT_MAX; 
        for(char c : t) hashMap[c]++; 
        int start = 0, end = 0, count = 0;  
        while(end < s.length()){
            if(hashMap[s[end]] > 0){
                count++; 
            }
            hashMap[s[end]]--; 
            while(count >= t.length()){
                if(end - start + 1 < min_len){
                    min_len = end - start + 1; 
                    min_index = start; 
                }
                if(hashMap[s[start]]++ == 0){
                    //hashMap[s[start]]++; 
                    count--; 
                }
                start++; 
            }
            end++; 
        }
        return min_len == INT_MAX ? "" : s.substr(min_index,min_len); 
    }
};