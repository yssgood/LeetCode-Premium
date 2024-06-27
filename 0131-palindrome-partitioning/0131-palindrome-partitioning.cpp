class Solution {
public:
    vector<vector<string>> answer; 
    bool isPalindrome(string& s){
        int start = 0, end = s.length()-1; 
        while(start < end){
            if(s[start] != s[end]) return false; 
            start++;
            end--; 
        }
        return true; 
    }
    void dfs(string& s, vector<string>& container, int index){
        if(index >= s.length()){
            answer.push_back(container);
            return; 
        }
        for(int i = index; i < s.length(); i++){
            string tmp = s.substr(index, i - index + 1);
            //cout << tmp << endl; 
            if(isPalindrome(tmp)){
                container.push_back(tmp);
                dfs(s,container,i+1); 
                container.pop_back(); 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> container;
        dfs(s,container,0);
        return answer; 
    }
};