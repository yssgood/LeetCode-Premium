class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,pair<int,int>> hashMap; 
        map<char,int> banned; 
        int count = 0; 

        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i]) && hashMap.count(tolower(word[i]))){
                if(hashMap[tolower(word[i])].second == -1) count++; 
                hashMap[tolower(word[i])].first = i; 
                hashMap[tolower(word[i])].second = 1; 
            } 

            if(islower(word[i])){
                if(hashMap[word[i]].second > 0 && i > hashMap[word[i]].first){
                    if(!banned.count(word[i])) count--; 
                    banned[word[i]]++; 
                } else{
                    hashMap[word[i]].first = i; 
                    hashMap[word[i]].second = -1; 
                }
            }
        }
        return count; 
    }
};