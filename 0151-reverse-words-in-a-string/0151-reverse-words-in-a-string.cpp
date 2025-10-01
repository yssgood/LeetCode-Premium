class Solution {
public:
    string reverseWords(string s) {
        //eulb si yks eth
        reverse(s.begin(),s.end()); 
        string answer = ""; 
        int start = 0;  
        while(start < s.length()){
            //cout << start << ' '; 
            while(start < s.length() && isspace(s[start])) start++; 
            int end = start; 
            while(end < s.length() && (isalpha(s[end]) || isdigit(s[end]))) end++; 
            
            string tmp = s.substr(start, end - start); 
            reverse(tmp.begin(),tmp.end());
            if(tmp.length() > 0) answer += tmp + ' '; 
            start = end; 
        }
        answer.pop_back(); 
        return answer; 
    }
};