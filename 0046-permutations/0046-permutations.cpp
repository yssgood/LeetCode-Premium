class Solution {
public:
    void dfs(vector<vector<int>>& answer, vector<int>& container, vector<int>& nums, vector<bool>& visited){
        if(container.size() >= nums.size()){
            answer.push_back(container); 
            return; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true; 
                container.push_back(nums[i]); 
                dfs(answer,container,nums,visited); 
                container.pop_back();
                visited[i] = false;  
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<int> container; 
        vector<bool> visited(nums.size(),false); 
        dfs(answer,container,nums,visited); 
        return answer; 
    }
};