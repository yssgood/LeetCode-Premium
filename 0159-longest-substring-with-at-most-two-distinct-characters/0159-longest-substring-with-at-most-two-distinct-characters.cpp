class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char,int> hashMap; 
        int left = 0, right = 0; 
        int answer = 0; 
        while(right < s.length()){
            hashMap[s[right]]++; 
            if(hashMap.size() <= 2) answer = max(answer, right - left + 1); 
            while(hashMap.size() > 2){
                
                hashMap[s[left]]--;
                if(hashMap[s[left]] <= 0) hashMap.erase(s[left]); 
                left++; 
            }



            right++; 
        }
        return answer; 
    }
};