class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string compare = strs[0]; 
        int len = compare.length(); 
        int n = strs.size(); 
        for(int i = 1; i < n; i++){
            while(strs[i].find(compare) != 0){
                compare = compare.substr(0,len--); 
            }
        }
        return compare; 
    }
};