class Solution {
public:
    vector<vector<int>> answer; 
    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& container){
        if(container.size() >= nums.size()){
            answer.push_back(container); 
            return; 
        }

        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true; 
                container.push_back(nums[i]); 
                dfs(nums,visited,container); 
                visited[i] = false; 
                container.pop_back(); 
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(),false); 
        vector<int> container; 
        dfs(nums,visited,container);
        return answer; 
    }
};