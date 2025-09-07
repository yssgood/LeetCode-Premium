class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create graph strcuture -> ourVec 
        
        vector<vector<pair<int,int>>> ourVec(n+1);
        
        for (int i = 0; i < times.size(); i++){
            vector<int> inner = times[i];
            int from = inner[0];
            int to = inner[1];
            int weight = inner[2];
            ourVec[from].push_back({to,weight});{}
        }
        
        
        //create distance vector 
        vector<int> distance(n+1,INT_MAX); 
        
        //declare priority_queue 
        //{type,vector<type>,greater<>} -> pq (min-heap) 
        //{type,vector<type>} -> pq (max-heap) 
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq; 
        
        //set-up 
        distance[k] = 0;
        pq.push({0,k}); //{distance, node} 
        
        
        //start your bfs using priority_queue
        while (!pq.empty()){
            int size = pq.size();
            for (int i = 0; i < size; i++){
                vector<int> curr = pq.top();
                pq.pop();
                
                int d = curr[0]; 
                int node = curr[1]; 
                
                for(pair<int,int> next :ourVec[node]){
                    int neighbor = next.first; 
                    int weight = next.second; 
                    
                    if(distance[node] + weight < distance[neighbor]){
                        distance[neighbor] = distance[node] + weight; 
                        pq.push({distance[neighbor], neighbor}); 
                    }
                    
                }
                 
            }
        }
        
        
        int maxTime = 0; 
        for(int i = 1; i <= n; i++){
            if(distance[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, distance[i]); 
        }
        
        return maxTime; 
    }
};



/* 

[0,1] [0,2] 

ourVec 
[0] -> {1,2} 
[1] -> {0}
[2] -> {0} 

[2,1,1] [2,3,1] 

ourVec 
[1]
[2] -> {(1,1),(3,1)} 
[3] 

[1,0,1,2,INT_MAX]
maximum time from this distance vector -> entire time to travel all the nodes 

*/ 