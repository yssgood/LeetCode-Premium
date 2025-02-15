class Solution {
public:
    void dfs(int& left, int& right, string& curr, vector<string>& answer, int n){
        if((left + right) >= (n * 2)){
            answer.push_back(curr); 
            return; 
        }

        if(left + 1 <= n){
            curr += '('; 
            left++; 
            dfs(left,right,curr,answer,n); 
            left--; 
            curr.pop_back(); 
        }

        if(left > right){
            curr += ')'; 
            right++;
            dfs(left,right,curr,answer,n); 
            right--; 
            curr.pop_back(); 
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer; 
        string curr = ""; 
        int left = 0, right = 0;
        dfs(left,right,curr,answer,n); 
        return answer; 
    }
};