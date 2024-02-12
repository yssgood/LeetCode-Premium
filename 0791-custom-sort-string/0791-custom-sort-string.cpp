class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ordMap; 
        for(int i = 0; i < order.length(); i++) ordMap[order[i]] = i; 
        for(char& c : s) if(!ordMap.count(c)) ordMap[c] = INT_MAX; 

        sort(s.begin(), s.end(), [&](char& a, char& b){
            return ordMap[a] < ordMap[b]; 
        });

        return s; 
    }
};