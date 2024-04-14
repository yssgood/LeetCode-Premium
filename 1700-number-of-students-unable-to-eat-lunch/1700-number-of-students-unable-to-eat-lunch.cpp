class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q; 
        stack<int> stck; 
        reverse(sandwiches.begin(), sandwiches.end()); 
        for(int i = 0; i < students.size(); i++){
            q.push(students[i]); 
            stck.push(sandwiches[i]); 
        }
        int size = students.size() * sandwiches.size(); 
        while(size-- && !q.empty()){
            int first = q.front(); 
            int top = stck.top(); 
            q.pop(); 
            if(first != top){
                q.push(first); 
            } else if(first == top){
                stck.pop(); 
            }
        }

        return q.size(); 
    }
};