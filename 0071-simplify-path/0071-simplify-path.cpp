class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack; 
        stringstream ss(path); 
        string tmp; 

        while(getline(ss,tmp,'/')){
            cout << tmp << ' '; 
            if(tmp == ".."){
                if(!stack.empty()) stack.pop_back(); 
            } else if(tmp != "." && !tmp.empty()){
                stack.push_back(tmp); 
            }
        }

        string res = ""; 
        for(auto str : stack) res += "/" + str;  
        if(res.empty()){
            return "/"; 
        } else{
            return res; 
        }
    }
};