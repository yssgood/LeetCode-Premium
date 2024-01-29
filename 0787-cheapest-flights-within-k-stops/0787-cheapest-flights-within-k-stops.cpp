class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); 

        for(vector<int>& v : flights){
            int from = v[0], to = v[1], price = v[2]; 
            adj[from].push_back({to,price}); 
        }

        vector<int> nodeInfo(n, INT_MAX); 
        nodeInfo[src] = 0; 
        //priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        priority_queue<vector<int>> pq; 
        pq.push({0,src,k+1}); 

        while(!pq.empty()){
            int size = pq.size(); 
            for(int i = 0; i < size; i++){
                
                vector<int> first = pq.top(); 
                pq.pop(); 

                int dist = first[0]; 
                int node = first[1]; 
                int steps = first[2]; 

                if(steps > 0){
                    for(pair<int,int>& p : adj[node]){
                        int dest = p.first, weights = p.second; 
                        if(nodeInfo[node] + weights < nodeInfo[dest]){
                            nodeInfo[dest] = nodeInfo[node] + weights; 
                            int newDist = nodeInfo[dest]; 
                            pq.push({newDist,dest,steps-1}); 
                        }
                    }
                }

            }
        }
        if(nodeInfo[dst] != INT_MAX) return nodeInfo[dst]; 
        return -1; 
    }
};