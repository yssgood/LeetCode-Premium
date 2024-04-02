class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> sMap, tMap; 
        for(int i = 0; i < s.length(); i++){
            
            if(!sMap.count(s[i]) && !tMap.count(t[i])){
                sMap[s[i]] = t[i]; 
                tMap[t[i]] = s[i]; 
            } else if(sMap[s[i]] != t[i] || tMap[t[i]] != s[i]) return false; 
        }
        return true; 
    }
};