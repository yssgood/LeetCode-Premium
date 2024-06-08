class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int start1 = 0;
        int start2 = 0; 
        string answer = ""; 
        while(start1 < word1.length() && start2 < word2.length()){
            answer += word1[start1++]; 
            answer += word2[start2++]; 
        }

        if(word1.length() > word2.length()){
            answer += word1.substr(start1); 
        } else{
            answer += word2.substr(start2); 
        }

        return answer; 
    }
};