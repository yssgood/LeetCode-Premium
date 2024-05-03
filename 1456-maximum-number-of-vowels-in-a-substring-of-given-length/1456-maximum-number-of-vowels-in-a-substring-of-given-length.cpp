class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int> hashMap = {{'a',1}, {'e',1}, {'i',1}, {'o',1}, {'u',1}}; 
        int answer = INT_MIN, curr_max = 0; 
        int start = 0, end = 0; 

        while(end < s.length()){
            curr_max += hashMap.count(s[end]) ? 1 : 0; 
            if((end - start) + 1 >= k){
                answer = max(answer, curr_max); 
                curr_max -= hashMap.count(s[start]) ? 1 : 0; 
                start++; 
            }

            end++; 
        }

        return answer; 
    }
};