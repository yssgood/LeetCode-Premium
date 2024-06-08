class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end()); 
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                int start = i; 
                int end = i; 

                while(end < s.length() && s[end] != ' ') end++; 
                i = end; 
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
                int start = i;  
                int  end = i; 
                while(end < s.length() && s[end] != ' ') end++; 
                i = end; 
                answer += s.substr(start, end - start); 
                answer += ' '; 
            }
        }
        answer.pop_back(); 
        //cout << answer; 

        return answer; 
    }
};