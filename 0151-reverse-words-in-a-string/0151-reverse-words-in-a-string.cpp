class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end()); 
        int start = 0, end = 0; 
        string answer = ""; 
        while(end < s.length()){
            while(start < s.length() && !isalnum(s[start])) start++; 
            end = start; 
            while(end < s.length() && isalnum(s[end])) end++; 
            string tmp = s.substr(start, end - start); 
            reverse(tmp.begin(),tmp.end()); 
            if(!tmp.empty()) answer += tmp + ' '; 
            start = end + 1; 
        }
        answer.pop_back();
        return answer; 
    }
};