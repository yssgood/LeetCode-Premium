class Solution {

public:
    void dfs(string& digits, vector<string>& container, map<char,vector<char>>& hashMap, string& empty, int index){

        if(empty.length() > 0 && empty.length() == digits.length()){
            container.push_back(empty);  
            return; 
        }

        for(int i = 0; i < hashMap[digits[index]].size(); i++){
            empty += hashMap[digits[index]][i]; 
            dfs(digits, container, hashMap, empty, index+1); 
            empty.pop_back(); 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> container; 
        map<char,vector<char>> hashMap = {{'2',{'a','b','c'}},{'3',{'d','e','f'}},{'4',{'g','h','i'}},{'5',{'j','k','l'}},{'6',{'m','n','o'}},
                                            {'7',{'p','q','r', 's'}},{'8',{'t','u','v'}},{'9',{'w','x','y','z'}}}; 


        string empty = ""; 
        dfs(digits,container,hashMap,empty,0); 


        return container; 
    }
};