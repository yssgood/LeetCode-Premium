class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> answer; 
        string curr = "a"; 
        int index = 0; 
        int last = 0; 
        while(index < target.length()){
            answer.push_back(curr); 
            last = curr.size()-1; 
            
            if(curr[last] != target[index]){
                curr[last] = 'a' + (curr[last] - 'a' + 1) % 26; 
            } else{
                index++; 
                curr += 'a'; 
            }
            //break; 
        }

        return answer; 
    }
};