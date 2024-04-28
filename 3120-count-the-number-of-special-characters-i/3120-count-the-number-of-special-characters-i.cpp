class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,pair<char,bool>> hashMap; 
        int count = 0; 
        for(int i = 0; i < word.length(); i++){
            if(hashMap.count(tolower(word[i]))){
                pair<char,bool> p = hashMap[tolower(word[i])]; 
                if(p.first != word[i] && p.second == false){
                    hashMap[tolower(word[i])] = {tolower(word[i]),true}; 
                    count++; 
                }
            } else{
                hashMap[tolower(word[i])] = {word[i],false}; 
            }
        }

        return count; 
    }
};