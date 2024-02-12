class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hashMap; 
        for(char& c : s) hashMap[c]++;

        sort(s.begin(), s.end(), [&](char& a, char& b){
            if(hashMap[a] == hashMap[b]) return a < b;
            return hashMap[a] > hashMap[b]; 
        });

        return s; 
    }
};