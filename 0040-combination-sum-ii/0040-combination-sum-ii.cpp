class Solution {
    set<vector<int>> v_set; 
public:
    void dfs(vector<int>& candidates, int& target, vector<int>& container, int index){
        if(target <= 0){
            if(target == 0){
                //cout << 'v' << endl; 
                vector<int> tmp = container; 
                sort(tmp.begin(), tmp.end()); 
                v_set.insert(tmp); 
            }
            return; 
        }

        for(int i = index; i < candidates.size(); i++){
            if(i && candidates[i] == candidates[i-1] && i > index) continue; 
            container.push_back(candidates[i]); 
            target -= candidates[i]; 
            dfs(candidates, target, container, i + 1); 
            container.pop_back();
            target += candidates[i]; 
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer; 
        vector<int> container; 
        int index = 0; 
        dfs(candidates, target, container, 0); 

        for(auto& it : v_set) answer.push_back(it); 

        return answer; 
    }
};