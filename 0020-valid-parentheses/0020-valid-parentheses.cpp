class Solution {
public:
    bool isValid(string s) {
        stack<char> stack; 
        map<char,char> hashMap = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char& c : s){
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c); 
            } else{
                if(stack.empty()) return false; 

                char top = stack.top();
                stack.pop(); 

                if(top != hashMap[c]) return false; 
            }
        }
        return stack.empty(); 
    }
};