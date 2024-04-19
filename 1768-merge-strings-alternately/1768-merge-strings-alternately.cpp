class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int min_length = min(word1.length(), word2.length()); 
        bool diff = false; 
        string tail = "", answer = ""; 
        if(word1.length() < word2.length()){
            tail = word2; 
        } else if(word1.length() > word2.length()){
            tail = word1; 
        }
        

        for(int i = 0; i < min_length; i++){
            answer += word1[i];
            answer += word2[i]; 
        }
        
        if(!tail.empty()){
            answer += tail.substr(min_length); 
        }
        
        return answer; 
    }
};