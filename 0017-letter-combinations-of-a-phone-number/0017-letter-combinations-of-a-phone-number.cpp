class Solution {
private:
    map<char,vector<char>> hashMap = {{'2', {'a','b','c'}},
                                    {'3', {'d','e','f'}},
                                    {'4', {'g','h','i'}},
                                    {'5', {'j','k','l'}},
                                    {'6', {'m','n','o'}},
                                    {'7', {'p','q','r','s'}},
                                    {'8', {'t','u','v'}},
                                    {'9', {'w','x','y','z'}}};
public:
    void dfs(string digits, string& tmp, vector<string>& answer, int index){
        if(tmp.length() >= digits.length()){
            answer.push_back(tmp);
            return; 
        }

        for(int i = 0; i < hashMap[digits[index]].size(); i++){
            tmp += hashMap[digits[index]][i]; 
            dfs(digits,tmp,answer,index+1); 
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        vector<string> answer; 
        string tmp = ""; 
        dfs(digits,tmp,answer,0); 
        return answer; 
    }
};