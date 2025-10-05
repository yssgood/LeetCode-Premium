class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()); 
        string first = strs[0]; 
        string last = strs[strs.size()-1]; 
        string answer = "";  

        //for(string n :strs) cout << n << endl; 

        for(int i = 0; i < first.length(); i++){
            if(last[i] != first[i]) break; 
            answer += first[i]; 
        }

        return answer; 
    }
};