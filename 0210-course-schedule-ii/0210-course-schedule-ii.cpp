class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // if(prerequisites.empty()){
        //     vector<int> answer; 
        //     for(int i = numCourses-1; i >= 0; i--){
        //         answer.push_back(i); 
        //     }
        //     return answer; 
        // }
        vector<int> inStack(numCourses,0); 
        vector<vector<int>> adj(numCourses); 
        for(vector<int>& v : prerequisites){
            int to = v[0], from = v[1]; 
            adj[from].push_back(to); 
            inStack[to]++; 
        }

        vector<int> answer; 
        int currCourse = 0; 
        queue<int> q; 
        for(int i = 0; i < numCourses; i++){
            if(inStack[i] == 0){
                q.push(i); 
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            //currCourse++; 
            for(int i = 0; i < size; i++){
                int currNode = q.front(); 
                q.pop(); 
                currCourse++; 
                answer.push_back(currNode); 
                for(int nextCourse : adj[currNode]){
                    inStack[nextCourse]--; 
                    if(inStack[nextCourse] == 0){
                        q.push(nextCourse); 
                    }
                }
            }
        }

        //cout << currCourse; 
        if(currCourse != numCourses) return {}; 
        
        return answer; 
    }
};


