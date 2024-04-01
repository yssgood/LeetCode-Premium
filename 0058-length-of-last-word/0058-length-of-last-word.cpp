class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s); 
        string word; 
        vector<string> v; 
        while(ss >> word){
            v.push_back(word);
        }
        return v[v.size()-1].length(); 
    }
};