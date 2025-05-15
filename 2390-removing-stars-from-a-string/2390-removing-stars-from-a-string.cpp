class Solution {
public:
    string removeStars(string s) {
        stack<char> stack; 
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                if(!stack.empty()) stack.pop(); 
                continue; 
            }
            stack.push(s[i]); 
        }

        string answer = ""; 
        while(!stack.empty()){
            answer += stack.top();
            stack.pop(); 
        }

        reverse(answer.begin(),answer.end()); 

        return answer; 
    }
};