class Solution {
vector<vector<int>> answer; 
public:
    void dfs(vector<int>& container, vector<int>& candidates, int target, int sum, int index){
        if(sum > target || index >= candidates.size()) return; 

        if(sum == target){
            answer.push_back(container); 
            return; 
        }

        for(int i = index; i < candidates.size(); i++){
            sum += candidates[i]; 
            container.push_back(candidates[i]); 
            dfs(container, candidates, target, sum, i); 
            sum -= candidates[i]; 
            container.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> container; 
        dfs(container, candidates, target, 0,0);


        return answer; 
    }
};