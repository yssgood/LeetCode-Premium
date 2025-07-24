class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer; 
        queue<int> q; 
        vector<int> inBound(numCourses); 
        vector<vector<int>> adj(numCourses); 

        for(vector<int>& v : prerequisites){
            int to = v[0], from = v[1]; 
            inBound[to]++; 
            adj[from].push_back(to); 
        }

        for(int i = 0; i < numCourses; i++){
            if(inBound[i] == 0){
                q.push(i); 
                answer.push_back(i); 
            }
        }

        int time = 0; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int node = q.front(); 
                q.pop(); 
                time++; 
                for(int nextNode : adj[node]){
                    inBound[nextNode]--; 
                    if(inBound[nextNode] == 0){
                        q.push(nextNode); 
                        answer.push_back(nextNode); 
                    }
                }
            }
        }

        if (time != numCourses) return {}; 
        return answer; 
    }
};