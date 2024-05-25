class Solution {
public:
    string findPattern(string& s){
        string res = string(1,'0');  

        for(int i = 1; i < s.length(); i++){
            int diff = s[i] - s[i-1] < 0 ? (s[i] - s[i-1]) + 26 : (s[i] - s[i-1]); 
            res += to_string(diff) + ","; 
        }
        return res; 
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> answer; 
        map<string,vector<string>> hashMap; 
        //cout << ('a' - 'b') + 26 << ' ' << ('z' - 'a'); 

        for(string& s : strings){
            string key = findPattern(s); 
            
            hashMap[key].push_back(s); 
        }

        for(auto& it : hashMap){
            vector<string> container; 
            for(string& ss : it.second){
                container.push_back(ss); 
            }
            answer.push_back(container); 
        }

        return answer; 
    }
};