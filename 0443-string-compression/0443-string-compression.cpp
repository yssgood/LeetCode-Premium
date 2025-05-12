class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1; 
        char curr = chars[0]; 
        int index = 1; 
        for(int i = 1; i < chars.size(); i++){
            count += chars[i]  == curr ? 1 : 0; 

            if(chars[i] != curr){
                curr = chars[i]; 
                if(count > 1){
                    string tmp = to_string(count); 
                    for(char c : tmp) chars[index++] = c; 
                    chars[index++] = chars[i]; 
                } else{
                    chars[index++] = chars[i]; 
                }

                count = 1; 
                
            }
        }

        if(count > 1){
            string tmp = to_string(count); 
            for(char c : tmp) chars[index++] = c; 
        }

        return index; 
    }
};