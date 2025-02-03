class Solution {
public:
    string minWindow(string s, string t) {
        string answer = ""; 
        map<char,int> hashMap; 
        for(char c : t) hashMap[c]++; 
        int start = 0, end = 0; 
        int min_len = INT_MAX, min_start = 0; 
        int count = 0; 
        while(end < s.length()){
            char curr = s[end]; 
            if(hashMap[s[end]] > 0){
                count++; 
            }
            hashMap[s[end]]--; 

            while(count >= t.length()){
                if(end - start + 1 < min_len){
                    min_len = end - start + 1; 
                    min_start = start; 
                }
                // if(tMap.count(s[start])){
                //     tMap[s[start]]++; 
                //     count--; 
                // }
                if(hashMap[s[start]]++ == 0){
                    count--; 
                }
                start++; 
            }

            end++; 
        }


        return min_len == INT_MAX ? "" : s.substr(min_start, min_len); 
    }
};