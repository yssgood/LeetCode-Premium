class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> container; 
        stringstream ss(s); 
        string tmp; 
        while(ss >> tmp){
            container.push_back(tmp); 
        }

        map<char,string> patternMap; 
        map<string,char> stringMap; 

        if(container.size() != pattern.length()) return false; 

        for(int i = 0; i < pattern.length(); i++){
            char p = pattern[i]; 
            string compare = container[i]; 

            if(patternMap.count(p) && patternMap[p] != compare || stringMap.count(compare) && stringMap[compare] != p) return false; 

            patternMap[p] = compare; 
            stringMap[compare] = p; 
        }
        return true; 
    }
};