class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        vector<double> maxProb(n, 0.0);
        priority_queue<vector<double>> pq;  // Max-heap by default
        
        maxProb[start] = 1.0;
        pq.push({1.0, (double)start});  // {probability, node}
        
        while (!pq.empty()) {
            vector<double> front = pq.top();
            pq.pop();
            
            double prob = front[0];
            int node = (int)front[1];
            
            //if (node == end) return prob;
            //if (prob < maxProb[node]) continue;
            
            for (auto& p : adj[node]) {
                int neighbor = p.first;
                double edgeProb = p.second;
                double newProb = prob * edgeProb;
                
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, (double)neighbor});
                }
            }
        }
        
        return maxProb[end];
    }
};