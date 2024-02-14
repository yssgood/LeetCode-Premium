class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(vector<int>& v : shift){
            int dir = v[0], amount = v[1]; 
            if(dir == 0) s = s.substr(amount % s.length()) + s.substr(0,amount % s.length()); 
            if(dir == 1) s = s.substr(s.length() - (amount % s.length())) + s.substr(0,s.length() - amount % s.length()); 
            //cout << s << endl; 
        }
        return s; 
    }
};