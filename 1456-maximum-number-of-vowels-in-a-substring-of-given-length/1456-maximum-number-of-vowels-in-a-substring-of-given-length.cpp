class Solution {
public:
    map<char,int> vowels = {{'a',1}, {'e',1}, {'i',1}, {'o',1}, {'u',1}};
    int maxVowels(string s, int k) {
        int curr_max = 0; 
        int start = 0, end = 0; 
        int answer = 0; 
        while(end < s.length()){
            curr_max += vowels.count(s[end]) ? 1 : 0; 
            if(end - start + 1 >= k){
                answer = max(answer, curr_max); 
                if(vowels.count(s[start])) curr_max--; 
                start++; 
            }


            end++; 
        }
        return answer; 
    }
};