class Solution {
public:
    int shortestWay(string source, string target) {
        //if(source.length() > target.length()) return -1; 
        
        int start = 0, end = 0; 
        int answer = 0; 
        
        while(end < target.length()){
            
            bool flag = false; 
            while(start < source.length()){
                if(source[start] == target[end]){
                    flag = true; 
                    end++; 
                }
                start++; 
            }

            //cout << start << ' ' << flag << endl; 
            if(!flag) return -1; 
            if(start >= source.length() - 1){
                start = 0; 
            }
            answer++; 
            
        }
        
        
        return answer; 
    }
};