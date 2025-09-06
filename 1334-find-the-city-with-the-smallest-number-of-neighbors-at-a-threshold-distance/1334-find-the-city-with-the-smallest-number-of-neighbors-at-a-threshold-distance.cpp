class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Distance to self is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Fill direct edges
        for (auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        // Floyd-Warshall
        for (int through = 0; through < n; through++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if (dist[from][through] != INT_MAX && dist[through][to] != INT_MAX) {
                        dist[from][to] = min(dist[from][to], dist[from][through] + dist[through][to]);
                    }
                }
            }
        }
        
        // Find city with minimum reachable cities
        int result = 0, minCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                result = i;
            }
        }
        
        return result;
    }
};