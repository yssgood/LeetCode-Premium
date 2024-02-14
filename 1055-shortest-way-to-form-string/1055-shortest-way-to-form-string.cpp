class Solution {
public:
    int shortestWay(string source, string target) {
        int left = 0, right = 0; 
        int answer = 0;  
        bool flag = false; 

        while(right < target.length()){
            left = 0; 
            while(left < source.length()){
                if(source[left] == target[right]){
                    left++;
                    right++; 
                    flag = true; 
                } else{
                    left++; 
                }
            }
            if(!flag) return -1; 
            answer ++; 
            flag = false; 
        }

        return answer; 
    }
};