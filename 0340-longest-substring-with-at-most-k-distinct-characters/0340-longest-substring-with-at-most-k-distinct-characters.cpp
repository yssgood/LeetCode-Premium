class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        map<char,int> hashMap; 
        int start = 0, end = 0, answer = 0; 

        while(end < s.length()){
            hashMap[s[end]]++; 
            if(hashMap.size() <= k) answer = max(answer, end - start + 1);
            while(hashMap.size() > k){
                hashMap[s[start]]--;
                if(hashMap[s[start]] == 0) hashMap.erase(s[start]); 
                start++; 
            } 
            end++; 
        }

        return answer; 
    }
};