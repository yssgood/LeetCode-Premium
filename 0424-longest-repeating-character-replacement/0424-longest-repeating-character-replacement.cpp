class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = 0;  
        int start = 0, end = 0; 
        map<char,int> hashMap; 
        int curr_max = 0; 
        while(end < s.length()){
            hashMap[s[end]]++; 
            curr_max = max(curr_max, hashMap[s[end]]); 

            while((end - start + 1) - curr_max > k){
                hashMap[s[start]]--; 
                start++; 
            }

            answer = max(answer, end - start + 1);
            end++; 

        }

        return answer; 
    }
};