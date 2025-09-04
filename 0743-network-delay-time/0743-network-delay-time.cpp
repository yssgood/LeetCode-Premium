class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for (vector<int>& v : times) {
            int from = v[0], to = v[1], weight = v[2];
            adj[from].push_back({to, weight});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        dist[k] = 0;
        pq.push({0, k});  // {distance, node}
        
        while (!pq.empty()) {
            vector<int> front = pq.top();
            pq.pop();
            
            int d = front[0];
            int node = front[1];
            
            //if (d > dist[node]) continue;
            
            for (auto& p : adj[node]) {
                int neighbor = p.first;
                int weight = p.second;
                
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};