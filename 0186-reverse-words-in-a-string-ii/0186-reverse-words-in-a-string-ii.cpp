class Solution {
public:
    void reverseWords(vector<char>& s) {
        int start = 0, end = 0; 
        while(end < s.size()){
            if(s[end] == ' '){
                int tmpEnd = end - 1; 
                
                while(start < tmpEnd){
                    //cout << s[start] << ' ' << s[tmpEnd]; 
                    swap(s[start], s[tmpEnd]); 
                    start++; 
                    tmpEnd--; 
                }

                start = end + 1; 

            }

            if(end == s.size()-1){
                int tmpEnd = end; 

                while(start < tmpEnd){
                    swap(s[start], s[tmpEnd]); 
                    start++;
                    tmpEnd--; 
                }
            }

            end++; 
        }

        reverse(s.begin(), s.end()); 
    }
};