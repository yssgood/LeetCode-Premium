class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string answer = ""; 
        for(vector<int>& v : shift){
            int dir = v[0], amt = v[1] % s.length(); 
            if(dir == 0){
                s = s.substr(amt) + s.substr(0,amt); 
                //cout << s << ' '; 
            } else{
                s = s.substr(s.length() - amt) + s.substr(0,s.length() - amt); 
            }  
        }

        return s; 
    }
};