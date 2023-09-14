class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& answer, vector<bool>& visited, vector<int>& container){
        if(container.size() == nums.size()){
            answer.push_back(container);
            return; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true; 
                container.push_back(nums[i]); 
                dfs(nums,answer,visited,container); 
                visited[i] = false; 
                container.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false); 
        vector<vector<int>> answer; 
        vector<int> container; 
        dfs(nums, answer, visited, container); 

        return answer; 
    }
};