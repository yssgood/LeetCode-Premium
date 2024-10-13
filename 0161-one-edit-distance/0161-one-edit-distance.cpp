class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.empty() && t.empty()) return false; 
        int len = min(s.length(), t.length()); 

        for(int i = 0; i < len; i++){
            if(s[i] != t[i]){
                if(s.length() == t.length()){
                    return (s.substr(i + 1) == t.substr(i + 1)); 
                } 
                if(s.length() < t.length()){
                    return (t.substr(i+1) == s.substr(i)); 
                }
                if(s.length() > t.length()){
                    return (s.substr(i+1) == t.substr(i)); 
                }
            }
        }
        if(s.length() > t.length()){
            return (t.length() + 1 == s.length()); //insert 
        }
        return (s.length() + 1 == t.length()); //insert
    }
};