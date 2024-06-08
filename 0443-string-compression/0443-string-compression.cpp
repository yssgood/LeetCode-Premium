class Solution {
public:
    int compress(vector<char>& chars) {
        string answer = ""; 
        int len = chars.size(); 
        for(int i = 0; i < chars.size(); i++){
            char curr = chars[i]; 
            answer += curr; 
            int end = i; 
            while(end < chars.size() && chars[end] == curr) end++; 
            if(end - i > 1) answer += to_string(end - i); 
            i = end - 1; 
        }

        for(char& c : answer){
            chars.push_back(c); 
        }
        chars.erase(chars.begin(), chars.begin() + len); 
        return chars.size(); 
    }
};