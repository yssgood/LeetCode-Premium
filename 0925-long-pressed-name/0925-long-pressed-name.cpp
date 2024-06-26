class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int start = 0, end = 0; 
        while(start < name.length() || end < typed.length()){
            if(name[start] != typed[end]){
                //cout << start << ' ' << end << endl; 
                return false; 
            }

            char curr = name[start]; 
            start++; 
            end++; 
            //while(end < typed.length() && typed[end] != name[start]) end++; 
            if(name[start] != typed[end]){
                while(end < typed.length() && typed[end] == curr) end++; 
            }
            
        }
        
        return true; 
    }
};