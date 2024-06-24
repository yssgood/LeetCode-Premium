class Solution {
public:
    vector<vector<int>> answer;
    void dfs(int k , int& n, vector<int>& container,int curr){
        if(container.size() >= k){
            if(n == 0) answer.push_back(container); 
            return; 
        }

        for(int i = curr; i <= 9; i++){
            container.push_back(i); 
            n -= i; 
            dfs(k,n,container,i + 1);
            container.pop_back(); 
            n += i; 
        }
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> container; 
        int curr = 1; 
        dfs(k,n,container,curr); 
        return answer; 
    }
};