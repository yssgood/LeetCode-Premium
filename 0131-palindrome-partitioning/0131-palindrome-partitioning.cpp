class Solution {
public: 
    bool isPalindrome(string s){
        int start = 0, end = s.length() -1; 
        while(start <= end){
            if(s[start] != s[end]) return false; 
            start++;
            end--; 
        }
        return true; 
    }
    void dfs(vector<vector<string>>& answer, vector<string>& container, string s, int index){
        if(index >= s.length()){
            answer.push_back(container); 
        }

        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s.substr(index, i - index + 1))){
                container.push_back(s.substr(index, i - index + 1));
                dfs(answer, container, s, i + 1); 
                container.pop_back(); 
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer; 
        vector<string> container; 
        
        dfs(answer, container, s, 0); 

        return answer; 
    }
};