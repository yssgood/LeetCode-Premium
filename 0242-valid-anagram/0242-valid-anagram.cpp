class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> sMap; 
        for(char c : s) sMap[c]++;
        for(char c : t) sMap[c]--; 
        for(auto& it : sMap){
            if(it.second != 0) return false; 
        }
        return true;
    }
};