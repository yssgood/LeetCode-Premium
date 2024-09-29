class Solution {
public:
    char kthCharacter(int k) {
        string answer = string(1,'a'); 
        
        while(answer.length() <= k){
            string tmp = answer; 
            for(int i = 0; i < tmp.length(); i++){
                tmp[i] = (char)(tmp[i] + 1 % 26); 
            }
            answer += tmp; 
        }


        return answer[k-1]; 
    }
};