class Solution {
public:
    void dfs(vector<vector<int>>& answer, vector<int>& nums, int index, vector<int>& container){
        answer.push_back(container);  
        for(int i = index; i < nums.size(); i++){
            container.push_back(nums[i]); 
            dfs(answer,nums,i+1,container);
            container.pop_back(); 
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<int> container; 
        dfs(answer,nums,0,container);
        return answer; 
    }
};