class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer; 
        vector<int> inward(numCourses,0); 
        queue<int> q; 
        vector<vector<int>> adj(numCourses); 

        for(vector<int>& v : prerequisites){
            int from = v[1], to = v[0]; 
            inward[to]++; 
            adj[from].push_back(to); 
        }

        for(int i = 0; i < numCourses; i++){
            if(inward[i] == 0) q.push(i);  
        }

        if(q.empty()) return {}; 

        int visitedCourse = 0; 

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                int currNode = q.front(); 
                q.pop(); 
                answer.push_back(currNode); 
                visitedCourse++; 
                for(int next : adj[currNode]){
                    inward[next]--; 
                    if(inward[next] <= 0){
                        q.push(next); 
                    }
                }
            }
        }

        if(visitedCourse != numCourses) return {}; 

        return answer; 
    }
};