class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        map<char,int> hashMap; 
        int answer = 0, start = 0, end = 0; 
        
        while(end < s.length()){
            if(hashMap.count(s[end])){
                while(start <= hashMap[s[end]]){
                    hashMap.erase(s[start]); 
                    start++; 
                }
                hashMap[s[end]] = end; 
            } else{
                hashMap[s[end]] = end; 
            }

            if(end - start + 1 == k){
                answer++;
                hashMap.erase(s[start]);  
                start++; 
            }

            end++; 
        }

        return answer; 
    }
};