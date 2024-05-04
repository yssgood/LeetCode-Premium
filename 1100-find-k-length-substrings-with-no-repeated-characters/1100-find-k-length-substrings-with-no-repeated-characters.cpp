class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        map<char,int> hashMap; 
        int answer = 0, start = 0, end = 0; 
        
        while(end < s.length()){
            if(hashMap.count(s[end])){
                //do something 
                while(start <= hashMap[s[end]]){
                    hashMap.erase(s[start]); 
                    start++; 
                }
                //start = hashMap[s[end]]; 
                //start++; 
                hashMap[s[end]] = end; 
                //cout << end << ' ' << start << ' ' << endl; 
            } else{
                hashMap[s[end]] = end; 
            }

            if(end - start + 1 == k){
                //cout << end << ' ' << start << ' ' << endl; 
                answer++;
                hashMap.erase(s[start]);  
                start++; 
            }

            end++; 
        }

        return answer; 
    }
};