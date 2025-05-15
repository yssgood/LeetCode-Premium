class Solution {
public:
    string decodeString(string s) {
        stack<char> charStack; 
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){
                string tmp = ""; 
                while(!charStack.empty() && charStack.top() != '['){
                    tmp += charStack.top(); 
                    charStack.pop(); 
                }
                charStack.pop(); 
                string num = ""; 
                while(!charStack.empty() && isdigit(charStack.top())){
                    num += charStack.top();
                    charStack.pop(); 
                }
                reverse(num.begin(),num.end()); 
                reverse(tmp.begin(),tmp.end()); 
                string res = ""; 
                int n = stoi(num); 
                for(int i = 0; i < n; i++) res += tmp; 
                //cout << res << endl; 
                for(char& c : res) charStack.push(c); 
            } else{
                charStack.push(s[i]); 
            }
        }

        string answer = ""; 

        while(!charStack.empty()){
            answer += charStack.top();
            charStack.pop(); 
        }

        reverse(answer.begin(),answer.end()); 

        return answer; 
    }
};