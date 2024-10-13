class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char,int> hashMap;
        for(char c : source) hashMap[c]++; 
        int start = 0;
        int end = 0; 
        int answer = 0; 
        while(end < target.length()){
            if(!hashMap.count(target[end])) return -1; 

            while(start < source.length() && end < target.length()){
                if(source[start] == target[end]){
                    start++;
                    end++; 
                } else{
                    start++; 
                }
            }

            answer++;
            if(start >= source.length()){
                start = 0; 
            }
            
        }
        return answer;
    }
};