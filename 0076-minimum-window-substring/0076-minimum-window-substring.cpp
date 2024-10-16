class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0; 
        string answer = ""; 
        unordered_map<char,int> hashMap; 
        for(char& c : t) hashMap[c]++; 

        int count = 0;
        int tmpStart = 0; 
        int minLength = INT_MAX; 
        while(end < s.length()){
            if(hashMap[s[end]]-- > 0){
                //hashMap[s[end]]--;
                count++; 
            }

            while(count >= t.length()){
 
                if(end - start + 1 < minLength){
                    tmpStart = start; 
                    minLength = end - start + 1; 
                }

                if(hashMap[s[start++]]++ == 0){
                    count--; 
                }

                // if(hashMap.count(s[start])){
                //     count--; 
                //     hashMap[s[start]]++; 
                // }
                // start++; 
            }

            end++; 
        }

        return minLength == INT_MAX ? "" : s.substr(tmpStart, minLength); 
    }
};