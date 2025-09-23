class Solution {
public:
    vector<int> parent, rank; 

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]); 
        }
        return parent[x]; 
    }


    bool unite(int x, int y){
        int px = find(x), py = find(y); 
        if(px == py) return false; 

        if (rank[px] < rank[py]){
            parent[px] = py; 
        } else if(rank[px] > rank[py]){
            parent[py] = px; 
        } else{
            parent[py] = px; 
            rank[px]++; 
        }
        return true; 
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        if (n <= 1) return 0; 

        parent.resize(n); 
        rank.resize(n, 0); 

        for(int i = 0; i < n; i++){
            parent[i] = i; 
        }

        vector<vector<int>> edges; 

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int weight = abs(points[i][0] - points[j][0]) + 
                                abs(points[i][1] - points[j][1]); 
                edges.push_back({weight, i, j}); 
            }
        }

        sort(edges.begin(), edges.end()); 

        int total_cost = 0; 
        int edges_used = 0; 

        for(auto& e : edges){
            int weight = e[0]; 
            int u = e[1]; 
            int v = e[2];  

            if(unite(u,v)){
                total_cost += weight;  
                edges_used++; 

                if(edges_used == n-1) break; 
            }

        }

        return total_cost;

    }
};