class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false; 

        vector<int> word1Map(26,0); 
        vector<int> word2Map(26,0); 

        for(int i = 0; i < word1.size(); i++){
            word1Map[word1[i] - 'a']++; 
            word2Map[word2[i] - 'a']++; 
        }

        for(int i = 0; i < word1Map.size(); i++){
            //if(word1Map[i] != word2Map[i]) return false; 
            if((word1Map[i] == 0 && word2Map[i] > 0) || (word2Map[i] == 0 && word1Map[i] > 0)){
                return false; 
            }
        } 

        sort(word1Map.begin(),word1Map.end()); 
        sort(word2Map.begin(),word2Map.end()); 


        return word1Map == word2Map; 
    }
};