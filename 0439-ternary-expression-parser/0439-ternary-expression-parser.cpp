class Solution {
public:
    string parseTernary(string expression) {
        stack<char> charStack; 

        for(int i  = expression.size()-1; i >= 0; i--){
            
            char currChar = expression[i]; 

            if(currChar == '?'){
                char op = expression[i-1]; 

                char forTrue = charStack.top(); 
                charStack.pop();
                char forFalse = charStack.top();
                charStack.pop(); 

                if(op == 'T'){
                    charStack.push(forTrue); 
                } else{
                    charStack.push(forFalse); 
                }

                i--; 
            } else if(isdigit(currChar) || currChar == 'T' || currChar == 'F'){
                charStack.push(currChar); 
            }

        }

        return string(1,charStack.top()); 
    }
};