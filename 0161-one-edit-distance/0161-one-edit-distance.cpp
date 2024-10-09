class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.empty() && t.empty() || s == t) return false; 
        if(s.length() > t.length()){
            string tmp = s; 
            s = t;
            t = tmp; 
        }

        //cout << (s.length() + 1 == t.length()); 
        if(t.length() - s.length() > 1) return false; 

        for(int i = 0; i < s.length(); i++){

            if(s[i] != t[i]){
                //cout << s.substr(i,1) << ' ' << t.substr(i+1); 
                if(s.length() == t.length()) return s.substr(i+1) == t.substr(i+1); 
                return (s.substr(i) == t.substr(i+1)); //deleting this character equals s 
            }
        }
        
        return s.length() + 1 == t.length(); 
    }
};