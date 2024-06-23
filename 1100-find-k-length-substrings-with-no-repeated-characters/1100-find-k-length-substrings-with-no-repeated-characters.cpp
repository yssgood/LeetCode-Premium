class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int start = 0, end = 0; 
        int answer = 0;  
        unordered_map<char,int> hashMap; 
        while(end < s.length()){
            hashMap[s[end]]++; 
            while(hashMap[s[end]] > 1){
                hashMap[s[start]]--;
                start++; 
            }

            if(end - start + 1 == k){
                answer++; 
                hashMap[s[start]]--;
                start++; 
            }
            end++; 
        }
        return answer; 
    }
};