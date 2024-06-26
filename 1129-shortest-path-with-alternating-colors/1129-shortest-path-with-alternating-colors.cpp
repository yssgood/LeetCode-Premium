class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> answer(n, INT_MAX);  
        vector<vector<pair<int,int>>> adj(n); 
        for(vector<int>& v : redEdges){
            int from = v[0], to = v[1]; 
            adj[from].push_back({to,0}); 
        }
        for(vector<int>& v : blueEdges){
            int from = v[0], to = v[1]; 
            adj[from].push_back({to,1}); 
        }

        queue<vector<int>> q; 
        q.push({0,-1,0}); 
        answer[0] = 0; 

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int> curr = q.front(); 
                q.pop(); 

                int node = curr[0], color = curr[1], dist = curr[2];  

                for(pair<int,int>& p : adj[node]){
                    int nextNode = p.first, nextColor = p.second; 
                    if(nextColor != color && answer[nextNode] > dist + 1){
                        answer[nextNode] = dist + 1; 
                        q.push({nextNode, nextColor, dist + 1}); 
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(answer[i] == INT_MAX) answer[i] = -1; 
        }
        return answer; 
    }
};