class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 1, end = 0; 
        int count = 0; 
        int n = chars.size(); 
        while(end < n){
            char curr = chars[end]; 
            while(end < n && chars[end] == curr){
                end++;
                count++; 
            }
            string tmp = to_string(count); 
            if(count > 1){
                for(char& c : tmp) chars[index++] = c; 
            }
            //cout << index << ' ' << end << endl; 
            if(end < n) chars[index++] = chars[end]; 
            count = 0; 
            curr = chars[end]; 
        }

        return index; 
    }
};