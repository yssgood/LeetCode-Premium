class Solution {
public:
    string simplifyPath(string path) {
        stack<string> unixStack; 
        stringstream ss(path); 
        string token; 

        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue; 
            } else if(token == ".."){
                if(!unixStack.empty()) unixStack.pop(); 
            } else{
                unixStack.push(token); 
            }
        }

        string answer = ""; 
        while(!unixStack.empty()){
            answer = "/" + unixStack.top() + answer; 
            unixStack.pop(); 
        }
        return answer.empty() ? "/" : answer; 
    }
};