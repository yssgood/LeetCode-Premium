class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n); 
        int INF = 987654321; 
        for(vector<int>& v : flights){
            int node = v[0], dest = v[1], dist = v[2]; 
            graph[node].push_back({dest,dist}); 
        }
        priority_queue<vector<int>> pq; 
        vector<int> distance(n,INF); 
        distance[src] = 0;
        pq.push({0,src,k+1}); //distance, curr_node, number of stops 
        
        while(!pq.empty()){
            int size = pq.size();
            for(int i = 0; i < size; i++){
                vector<int> first = pq.top(); 
                pq.pop();
                
                int dist = first[0], curr_node = first[1], stops = first[2]; 
                
                if(stops > 0){
                    for(pair<int,int>& p : graph[curr_node]){
                        int dest = p.first, weights = p.second; 
                        if(distance[curr_node] + weights < distance[dest]){
                            distance[dest] = distance[curr_node] + weights;
                            int newDist = distance[dest]; 
                            pq.push({newDist,dest,stops-1}); 
                        }
                    }
                }
            }
        }
        
        if(distance[dst] != INF) return distance[dst]; 
        
        return -1; 
    }
};