class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> rows(numRows); 
        int currRow = 0; 
        bool up = false; 
        for(char& c : s){
            rows[currRow] += c; 

            if(currRow == 0 || currRow == numRows-1){
                up = !up; 
            }

            currRow += (up == true) ? 1 : -1; 
        }

        string answer = ""; 
        for(string s : rows){
            answer += s; 
        }
        return answer; 
    }
};