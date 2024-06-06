class Solution {
public:
    set<char> vowels = {'a','e','i','o','u'};
    int maxVowels(string s, int k) {
        int answer = 0; 
        int start = 0, end = 0; 
        int count = 0; 
        while(end < s.length()){
            if(vowels.count(s[end])) count++; 

            if(end - start + 1 == k){
                answer = max(answer, count); 
            }

            while(end - start + 1 >= k){
                if(vowels.count(s[start])) count--; 
                start++; 
            }

            end++; 
        }
        return answer; 
    }
};