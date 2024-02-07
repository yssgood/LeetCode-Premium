class Solution {
public:
    void dfs(vector<vector<int>>& answer, vector<int>& container, vector<bool>& visited, vector<int>& nums){
        if(container.size() >= nums.size()){
            answer.push_back(container);
            return; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true; 
                container.push_back(nums[i]); 
                dfs(answer,container,visited,nums);
                visited[i] = false; 
                container.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<bool> visited(nums.size(), false); 
        vector<int> container; 
        dfs(answer, container, visited, nums); 

        return answer; 
    }
};