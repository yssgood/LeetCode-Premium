class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.empty() && t.empty()) return false; 
        //if(s == t) return true; 

        if(s.length() == t.length()){
            for(int i = 0; i < s.length(); i++){
                if(s[i] != t[i]){
                    return (s.substr(i+1) == t.substr(i+1)); 
                }
            }
        } else if(s.length() < t.length()){
            for(int i = 0; i < s.length(); i++){
                if(s[i] != t[i]){ //insert 
                    return (s.substr(i) == t.substr(i+1)); 
                }
            }
            return t.length() - s.length() == 1; 
        } else{
            for(int i = 0; i < t.length(); i++){
                if(t[i] != s[i]){
                    return (s.substr(i+1) == t.substr(i)); 
                }
            }
        }

        return s.length() - t.length() == 1; 
    }
};