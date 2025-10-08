class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> isoMap; 
        map<char,char> isoTMap; 
        for(int i = 0; i < s.length(); i++){
            char sChar = s[i];
            char tChar = t[i]; 
            if(isoMap.count(sChar) && isoMap[sChar] != tChar || isoTMap.count(tChar) && isoTMap[tChar] != sChar){
                return false; 
            }

            isoMap[sChar] = tChar; 
            isoTMap[tChar] = sChar; 
        }
        return true; 
    }
};

/*
"badc"
"baba"
*/