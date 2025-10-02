class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> charMap; 
        int answer = 0, start = 0, end = 0; 
        while(end < s.length()){
            charMap[s[end]]++; 
            while(charMap[s[end]] > 1){
                charMap[s[start++]]--; 
            }
            answer = max(answer, end - start + 1);
            end++; 
        }
        return answer; 
    }
};