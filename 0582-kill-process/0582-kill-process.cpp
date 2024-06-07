class Solution {
public:
    vector<int> answer; 
    void dfs(vector<vector<int>>& adj, int kill){
        answer.push_back(kill); 
        for(int next : adj[kill]){
            dfs(adj,next); 
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int node_num = *max_element(pid.begin(), pid.end()); 
        vector<vector<int>> adj(node_num + 1); 
        for(int i = 0; i < pid.size(); i++){
            if(ppid[i] == 0) continue; //root 
            adj[ppid[i]].push_back(pid[i]); 
        }

        dfs(adj,kill);

        return answer; 
    }
};