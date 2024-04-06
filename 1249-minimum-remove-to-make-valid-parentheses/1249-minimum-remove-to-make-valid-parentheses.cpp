class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> charStack;
        string answer = "";  
        string tmp = ""; 
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                tmp += s[i]; 
            } else if(s[i] == '('){
                charStack.push({s[i],i}); 
                tmp += '?'; 
            } else{
                if(!charStack.empty()){
                    tmp += ')';
                    tmp[charStack.top().second] = '(';  
                    charStack.pop(); 
                } else{
                    tmp += '!'; 
                }
            }
        }

        for(char& c : tmp){
            if(c != '?' && c != '!'){
                answer += c; 
            }
        }
        return answer; 
    }
};