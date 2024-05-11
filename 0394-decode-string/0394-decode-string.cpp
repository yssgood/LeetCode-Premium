class Solution {
public:
    string decodeString(string s) {
        stack<char> stack; 
        for(int i = 0; i < s.length(); i++){
            char currChar = s[i]; 
            if(currChar == ']'){
                string tmp = ""; 
                while(stack.top() != '['){
                    tmp += stack.top(); 
                    stack.pop(); 
                }
                stack.pop(); 
                string numTmp = ""; 
                while(!stack.empty() && isdigit(stack.top())){
                    numTmp += stack.top(); 
                    stack.pop(); 
                }
                reverse(numTmp.begin(), numTmp.end()); 
                int num = stoi(numTmp); 
                string add = ""; 
                while(num--){
                    add += tmp; 
                }
                
                reverse(add.begin(), add.end()); 
                for(char& c : add) stack.push(c); 

            } else{
                stack.push(currChar); 
            }
        }

        string res; 
        while(!stack.empty()){
            res += stack.top(); 
            stack.pop(); 
        }

        reverse(res.begin(), res.end());
        return res; 
    }
};