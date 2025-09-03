class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
       vector<int> visited(n,INT_MAX); 
       vector<vector<pair<int,int>>> adj(n); 

       for(vector<int> & v : flights){
            int from = v[0], to = v[1], dist = v[2]; 
            adj[from].push_back({to,dist}); 
       }

       pq.push({0,src,0}); 
       //visited[src] = 0; 

       while(!pq.empty()){
            int size = pq.size(); 
            for(int i = 0; i < size; i++){
                vector<int> v = pq.top(); 
                pq.pop();  

                int dist = v[0], node = v[1], remain = v[2]; 

                if(remain > visited[node] || remain > k + 1) continue; 
                visited[node] = remain; 
                if(node == dst) return dist; 

                for(pair<int,int>& next : adj[node]){
                    int nextNode = next.first, nextDist = next.second; 

                    pq.push({dist + nextDist, nextNode, remain + 1});
                }
            }
       }
       return -1; 
    }
};