class Solution {
public:
    map<int,int> hashMap; 
    vector<int> answer; 
    void dfs(vector<vector<int>>& adj, int hashNode){
        answer.push_back(hashNode); 
        for(int next : adj[hashNode]){
            dfs(adj,next); 
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        
        
        for(int i = 0; i < pid.size(); i++){
            hashMap[pid[i]] = i; 
        }

        vector<vector<int>> adj(pid.size()+1); 
        hashMap[0] = pid.size(); 
        for(int i = 0; i < pid.size(); i++){
            //if(ppid[i] == 0) continue; 
            int to = hashMap[pid[i]];
            int from = hashMap[ppid[i]]; 
            adj[from].push_back(to); 
        }
        
        dfs(adj,hashMap[kill]); 

        for(int i = 0; i < answer.size(); i++){
            answer[i] = pid[answer[i]]; 
        }

        return answer; 
    }
};