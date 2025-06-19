class Solution {
public:
    int calculate(int first, int prev,string& s){
        int res = 0; 
        if(s == "*"){
            res = first * prev;  
        } else if(s == "+"){
            res = first + prev; 
        } else if(s == "-"){
            res = first - prev;  
        } else{
            res = first / prev; 
        }

        return res; 
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> stack; 

        for(string& s : tokens){
            if(s == "*" || s == "-" || s == "+" || s == "/"){
                int res = 0; 
                int prev = stoi(stack.top()); 
                stack.pop(); 
                int first = stoi(stack.top()); 
                stack.pop(); 
                res = calculate(first, prev, s); 
                stack.push(to_string(res)); 
            } else{
                stack.push(s); 
            }
        }

        return stoi(stack.top()); 
    }
};
