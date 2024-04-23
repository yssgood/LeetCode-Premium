class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        for(vector<int>& v : shift){
            int dir = v[0], steps = v[1] % s.length(); 
            if(dir == 0){
                s = s.substr(steps) + s.substr(0,steps); 
            } else{
                s = s.substr(s.length() - steps) + s.substr(0, s.length() - steps); 
            }
        }

        return s; 
    }
};