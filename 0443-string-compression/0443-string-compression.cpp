class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0, end = 0; 
        string answer = ""; 
        char currChar = chars[start];
        while(end < chars.size()){
            char nextChar = chars[end]; 

            if(nextChar != currChar){
                int len = end - start; 
                while(chars[start] == currChar){
                    start++; 
                }
                
                if(len > 1){
                    answer = answer + currChar + to_string(len); 
                } else{
                    answer += currChar; 
                    
                }
                currChar = chars[start]; 
            }


            if(end == chars.size()-1){
                int len = end - start + 1; 
                if(len > 1){
                    answer = answer + currChar + to_string(len); 
                } else{
                    answer += currChar; 
                }
            }
            end++; 
        }
        chars = {}; 
        for(char& c : answer){
            chars.push_back(c); 
        }

        return chars.size();
    }
};