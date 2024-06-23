class Solution {
public:
    string findKey(string& s){
        string ret = ""; 
        ret += '0'; 
        char curr = s[0]; 
        for(int i = 1; i < s.length(); i++){
            int diff = s[i] - curr < 0 ? (s[i] - curr) + 26 : (s[i] - curr); 
            curr = s[i];  
            ret += (diff + '0'); 
        }
        return ret; 
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> answer; 
        unordered_map<string,vector<string>> hashMap; 
        for(string& s : strings){
            string key = findKey(s); 

            hashMap[key].push_back(s); 
        }
        
        for(auto& it : hashMap){
            answer.push_back(it.second); 
        }

        return answer; 
    }
};