class Solution {
public:
    vector<string> answer; 
    void dfs(string& digits, int index, map<char,vector<char>>& hashMap, string& tmp){
        if(tmp.length() >= digits.length()){
            answer.push_back(tmp);
            return; 
        }


        for(int i = 0; i < hashMap[digits[index]].size(); i++){
            tmp += hashMap[digits[index]][i];
            dfs(digits,index+1,hashMap,tmp);
            tmp.pop_back(); 
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        map<char,vector<char>> hashMap = {{'2', {'a','b','c'}},
                                            {'3', {'d','e','f'}},
                                            {'4', {'g','h','i'}},
                                            {'5', {'j','k','l'}},
                                            {'6', {'m','n','o'}},
                                            {'7', {'p','q','r','s'}},
                                            {'8', {'t','u','v'}},
                                            {'9', {'w','x','y','z'}}};

        string tmp = ""; 
        dfs(digits,0,hashMap,tmp); 
        return answer; 
    }
};