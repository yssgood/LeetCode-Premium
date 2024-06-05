class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> hashMap; 
        int start = 0, end = 0; 
        int curr_max = 0; 
        int answer = 0; 
        while(end < s.length()){
            hashMap[s[end]]++; 
            curr_max = max(curr_max, hashMap[s[end]]); 

            if((end - start +1) - curr_max > k){
                hashMap[s[start]]--; 
                start++; 
            }

            answer = max(answer, end - start + 1); 
            end++; 
        }
        return answer; 
    }
};