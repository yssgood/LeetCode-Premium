class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0; 
        unordered_map<char,int> hashMap; 
        int answer = 0; 
        while(end < s.length()){
            hashMap[s[end]]++; 
            while(hashMap[s[end]] > 1){
                hashMap[s[start]]--; 
                start++; 
            }
            answer = max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
};