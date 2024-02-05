class Solution {

map<char, vector<char>> numMap = {{'2', {'a','b','c'}},
                                {'3', {'d','e','f'}},
                                {'4', {'g','h','i'}},
                                {'5', {'j','k','l'}},
                                {'6', {'m','n','o'}},
                                {'7', {'p','q','r','s'}},
                                {'8', {'t','u','v'}},
                                {'9', {'w','x','y','z'}}};


public:
    void dfs(string& digits, string& empty, vector<string>& answer, int index){
        if(empty.length() >= digits.length()){
            answer.push_back(empty); 
            return; 
        }

        for(int i = 0; i < numMap[digits[index]].size(); i++){
            empty += numMap[digits[index]][i]; 
            dfs(digits,empty,answer,index+1); 
            empty.pop_back(); 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        vector<string> answer; 
        string empty = ""; 
        dfs(digits,empty,answer,0); 

        return answer; 
    }
};