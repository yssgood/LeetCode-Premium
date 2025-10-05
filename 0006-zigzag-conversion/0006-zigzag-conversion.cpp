class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s; 
        vector<string> rows(numRows); 
        int currRow = 0; 
        bool flag = true; 
        for(int i = 0; i < s.length(); i++){
            rows[currRow] += s[i]; 

            if(currRow >= numRows - 1){
                flag = false; 
            }
            if(currRow == 0){
                flag = true; 
            }

            if(flag){
                currRow += 1; 
            } else{
                currRow -= 1; 
            }
        }

        string answer = ""; 
        for(string next : rows) answer += next; 
        return answer; 
    }
};