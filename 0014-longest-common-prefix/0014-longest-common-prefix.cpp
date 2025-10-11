class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()); 
        string answer = "";
        int m = strs.size()-1;  
        for(int i = 0; i < strs[0].length(); i++){
            if(strs[0][i] == strs[m][i]) answer += strs[0][i]; 
            else break; 
        }
        return answer; 
    }
};