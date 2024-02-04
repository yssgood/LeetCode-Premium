class Solution {
public:
    void dfs(int left, int right,string add, vector<string>& answer, int n){
        if(left == n && right == n){
            answer.push_back(add);
            return; 
        }
        
        if(left < n){
            add += '(';
            dfs(left+1,right,add,answer,n);
            add.pop_back(); 
        }
        if(right < left){
            add += ')';
            dfs(left,right+1,add,answer,n); 
            add.pop_back(); 
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string add = ""; 
        int left = 0, right = 0; 
        dfs(left,right,add,answer,n); 
        return answer; 
    }
};