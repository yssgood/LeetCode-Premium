class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& container, vector<vector<int>>& answer, vector<bool>& visited){
        if(container.size() >= nums.size()){
            answer.push_back(container);
            return; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                container.push_back(nums[i]); 
                dfs(nums,container,answer,visited); 
                container.pop_back(); 
                visited[i] = false;  
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<int> container; 
        vector<bool> visited(nums.size(), false); 
        dfs(nums,container,answer, visited); 
        return answer; 
    }
};