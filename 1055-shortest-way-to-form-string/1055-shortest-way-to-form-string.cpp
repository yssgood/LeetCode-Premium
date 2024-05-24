class Solution {
public:
    int shortestWay(string source, string target) {
        int sourceP = 0, targetP = 0; 
        int answer = 0; 

        while(targetP < target.length()){
            bool flag = false; 
            //cout << target[targetP] << ' '; 
            while(sourceP < source.length()){
                if(source[sourceP] == target[targetP]){
                    flag = true; 
                    sourceP++;
                    targetP++; 
                } else{
                    sourceP++; 
                }
            }

            if(sourceP >= source.length()){
                if(!flag) return -1; 
                sourceP = 0; 
            }

            //targetP++; 
            answer++; 
        }

        return answer; 
    }
};