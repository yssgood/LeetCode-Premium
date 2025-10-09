class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int answer = 0; 
        stack<int> numStack; 
        for(string& t : tokens){
            if(t == "+"){
                int first = numStack.top(); 
                numStack.pop(); 
                int second = numStack.top(); 
                numStack.pop(); 
                numStack.push(second + first); 
            } else if(t == "-"){
                int first = numStack.top(); 
                numStack.pop(); 
                int second = numStack.top(); 
                numStack.pop(); 
                //cout << first << ' ' << second << ' ' << (second + first) << endl; 

                numStack.push(second - first); 
            } else if(t == "*"){
                int first = numStack.top(); 
                numStack.pop(); 
                int second = numStack.top(); 
                numStack.pop(); 
                numStack.push(second * first); 
            } else if(t == "/"){
                int first = numStack.top(); 
                numStack.pop(); 
                int second = numStack.top(); 
                numStack.pop(); 
                //cout << first << ' ' << second << ' ' << (second / first) << endl; 
                numStack.push(second / first); 
            } else{
                int num = 0; 
                if(t[0] == '-'){
                   num = stoi(t.substr(1)) * -1;  
                } else{
                    num = stoi(t); 
                }
                numStack.push(num); 
            }
        }

        cout << numStack.top(); 

        return numStack.top(); 
    }
};