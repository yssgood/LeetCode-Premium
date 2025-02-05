class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true; 
        map<char,int> hashMap; 
        int count = 0; 
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i]) count++; 
            if(count > 2) return false; 

            hashMap[s1[i]]++; 
            hashMap[s2[i]]--; 
        }

        for(auto& it : hashMap){
            if(it.second < 0) return false; 
        }
        return true; 
    }
};