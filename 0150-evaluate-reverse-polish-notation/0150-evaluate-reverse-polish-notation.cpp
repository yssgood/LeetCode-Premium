class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string& t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if(t == "+") st.push(a + b);
                else if(t == "-") st.push(a - b);
                else if(t == "*") st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(stoi(t));
            }
        }
        
        return st.top();
    }
};