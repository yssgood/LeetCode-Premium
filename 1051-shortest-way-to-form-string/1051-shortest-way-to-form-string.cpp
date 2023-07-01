class Solution {
public:
    int shortestWay(string source, string target) {
        if(source == target) return 0; 
        int t = 0;
        int count = 0; 
        
        while(t < target.length()){
            int s = 0; 
            bool flag = false;
            while(s < source.length() && t < target.length()){
                if(source[s] == target[t]){
                    flag = true; 
                    s++; t++; 
                }
                else{
                    s++; 
                }
            }
            if(flag == true) count++; 
            else return -1; 
        }
        if(t == target.length()) return count;
        return -1;  
        
    }
};