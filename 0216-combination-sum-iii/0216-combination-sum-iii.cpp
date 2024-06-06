class Solution {
public:
    vector<vector<int>> answer; 
    vector<int> container; 
    void dfs(int num, int& sum, int k, int target){
        if(container.size() >= k){
            if(sum == target){
                answer.push_back(container); 
            }
            return; 
        }

        for(int i = num; i <= 9; i++){
            container.push_back(i);
            sum += i;
            dfs(i + 1, sum, k, target);
            container.pop_back();
            sum -= i; 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = 0; 
        dfs(1,sum,k,n);
        return answer;     
    }
};