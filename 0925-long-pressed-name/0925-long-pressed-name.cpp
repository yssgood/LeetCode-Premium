class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1 = 0, p2 = 0; 
        while(p1 < name.length() || p2 < typed.length()){
            if(name[p1] != typed[p2]) return false; 

            int compare = name[p1]; 
            p1++; 
            p2++; 

            if(name[p1] != typed[p2]){ //in a long pressed zone 
                while(p2 < typed.length() && typed[p2] == compare) p2++; 
            }

        }
        return true; 
    }
};