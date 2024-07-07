class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length(); 
        string copy = s;
        for(int i = 0; i < s.length(); i++){
            copy[i] = s[(i + k) % n]; 
        }
        return copy; 
    }
};