class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack; 
        map<char,char> hashMap = {{')' , '('}, {'}' , '{'}, {']' , '['}}; 
        for(char& c : s){
            if(c == '(' || c == '[' || c == '{'){
                charStack.push(c); 
            } else{
                char lastOpen = ' '; 
                if(!charStack.empty()){
                    lastOpen = charStack.top();
                }

                if(lastOpen == hashMap[c]){
                    charStack.pop(); 
                } else{
                    return false; 
                }
            }
        }

        return charStack.empty(); 
    }
};