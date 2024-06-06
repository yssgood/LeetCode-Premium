class Solution {
public:
    vector<vector<int>> answer; 
    void dfs(vector<int>& candidates, int& target, vector<int>& container, int index){
        if(target <= 0){
            if(target == 0){
                answer.push_back(container); 
            }
            return; 
        }

        for(int i = index; i < candidates.size(); i++){
            container.push_back(candidates[i]); 
            target -= candidates[i];
            dfs(candidates, target, container, i); 
            container.pop_back(); 
            target += candidates[i]; 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> container; 

        dfs(candidates,target,container,0); 

        return answer; 
    }
};