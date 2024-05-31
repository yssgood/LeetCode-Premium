class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> hashMap; 
        for(char& c : s) hashMap[c]++; 
        for(char& c : t) hashMap[c]--; 

        for(auto& it : hashMap){
            //cout << it.first << ' ' << it.second << endl; 
            if(it.second < 0 || it.second > 0) return false; 
        }
        return true; 
    }
};