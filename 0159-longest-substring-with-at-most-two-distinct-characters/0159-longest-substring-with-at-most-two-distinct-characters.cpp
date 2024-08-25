class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, end = 0; 
        map<char,int> hashMap;
        int answer = 0;  
        while(end < s.length()){
            hashMap[s[end]]++; 

            while(hashMap.size() > 2){
                hashMap[s[start]]--; 
                if(hashMap[s[start]] <= 0) hashMap.erase(s[start]); 
                start++; 
            }

            answer = max(answer, end -start + 1); 
            end++; 
        }
        return answer; 
    }
};