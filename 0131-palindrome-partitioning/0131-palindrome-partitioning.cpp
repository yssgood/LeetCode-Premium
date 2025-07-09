class Solution {
public:
    bool isPalindrome(string tmp){
        int start = 0, end = tmp.length()-1;
        while(start < end){  // Changed <= to < (small optimization)
            if(tmp[start] != tmp[end]) return false;
            start++;
            end--; 
        }
        return true; 
    }
    
    void dfs(string& s, vector<vector<string>>& answer, vector<string>& container, int index){
        if(index >= s.length()){
            answer.push_back(container); 
            return; 
        }

        for(int i = index; i < s.length(); i++){
            // Extract substring from index to i
            string substring = s.substr(index, i - index + 1);
            
            if(isPalindrome(substring)){
                container.push_back(substring); 
                dfs(s, answer, container, i + 1);  // Move to next position after i
                container.pop_back(); 
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer; 
        vector<string> container; 
        dfs(s, answer, container, 0); 
        return answer; 
    }
};