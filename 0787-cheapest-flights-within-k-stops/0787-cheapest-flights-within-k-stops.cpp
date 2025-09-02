class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& adj, vector<vector<int>>& dist, 
             int src, int dst, int k, int stopsUsed) {
        if (stopsUsed > k + 1) return;  // Too many stops
        
        for (auto& p : adj[src]) {
            int next = p.first;
            int price = p.second;
            int newStops = stopsUsed + 1;
            
            // Check if this path is better
            if (newStops <= k + 1 && dist[src][stopsUsed] + price < dist[next][newStops]) {
                dist[next][newStops] = dist[src][stopsUsed] + price;
                dfs(adj, dist, next, dst, k, newStops);
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        // dist[node][stops] = minimum cost to reach node using exactly 'stops' stops
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;  // Start at source with 0 stops
        
        dfs(adj, dist, src, dst, k, 0);
        
        // Find minimum among all valid stop counts
        int result = INT_MAX;
        for (int stops = 0; stops <= k + 1; stops++) {
            result = min(result, dist[dst][stops]);
        }
        
        return result == INT_MAX ? -1 : result;
    }
};