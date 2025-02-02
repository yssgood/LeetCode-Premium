class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end()); 
        string answer = ""; 
        string last = strs.back(); 
        string first = strs[0]; 
        for(int i = 0; i < first.length(); i++){
            if(first[i] == last[i]){
                answer.push_back(first[i]); 
            } else{
                break; 
            }
        }
        return answer; 
    }
};