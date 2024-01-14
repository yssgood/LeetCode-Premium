class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false; 
        map<char,int> map1,map2; 

        for(int i = 0; i < word1.length(); i++){
            map1[word1[i]]++; 
            map2[word2[i]]++; 
        }

        for(auto& it : map1){
            if(!map2.count(it.first)) return false; 
        }
        
        vector<int> v1, v2; 
        for(auto& it : map1){
            v1.push_back(it.second); 
            v2.push_back(map2[it.first]); 
        }

        sort(v1.begin(),v1.end()); 
        sort(v2.begin(),v2.end()); 


        return (v1 == v2); 
    }
};