class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end()); 
        int start = 0, end = 0; 
        while(end < s.size()){
            if(isalnum(s[end])){
                start = end; 
                while(end < s.size() && isalnum(s[end])){
                    end++; 
                }
                
                int tmp = end-1; 

                while(start < tmp){
                    swap(s[start], s[tmp]);
                    start++;
                    tmp--;  
                }
            }
            end++; 
        }
    }
};