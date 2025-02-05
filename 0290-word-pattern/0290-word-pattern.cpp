class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec; 
        string tmp; 
        stringstream ss(s); 
        while(ss >> tmp){
            vec.push_back(tmp); 
        }
        map<string,char> reverseMap; 
        map<char,string> hashMap; 
        if(pattern.length()!= vec.size()) return false; 
        for(int i = 0; i < pattern.length(); i++){
            char curr = pattern[i]; 
            string target = vec[i]; 
            if(hashMap.count(curr) && hashMap[curr] != target) return false; 
            if(reverseMap.count(target) && reverseMap[target] != curr) return false; 

            hashMap[curr] = target;
            reverseMap[target] = curr; 
        }
        return true; 
    }
};