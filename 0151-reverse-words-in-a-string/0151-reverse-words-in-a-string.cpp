class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); 
        int start = 0, end = 0; 
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                
                start = i;
                end = i; 
                while(end < s.length() && s[end] != ' ') end++; 
                i = end; 
                //i += (end - i); 
                end--; 
                while(start < end){
                    swap(s[start], s[end]);
                    start++;
                    end--; 
                }
            }
        }
        string answer = ""; 
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                start = i;
                end = i; 

                while(end < s.length() && s[end] != ' ') end++; 
                i = end; 
                end--; 
                answer += s.substr(start, (end - start +1)) + ' '; 
            }
        }

        answer.pop_back(); 
        return answer; 
    }
};