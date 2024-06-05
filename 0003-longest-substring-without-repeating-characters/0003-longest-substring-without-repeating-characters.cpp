class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> hashMap; 
        int start = 0, end = 0; 
        int answer = 0; 
        while(end < s.length()){
            if(hashMap.count(s[end])){
                while(s[start] != s[end]){
                    hashMap[s[start]]--; 
                    if(hashMap[s[start]] == 0) hashMap.erase(s[start]); 
                    start++; 
                }
                hashMap[s[start]]--; 
                if(hashMap[s[start]] == 0) hashMap.erase(s[start]); 
                start++; 
            }
            
            hashMap[s[end]]++; 
            answer = max(answer, end - start + 1); 
            end++;
        }

        return answer; 
    }
};