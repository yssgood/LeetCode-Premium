/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public: 
    int dfs(vector<Employee*>& employees, int id, unordered_map<int,Employee*> hashMap){
        int sum = hashMap[id]->importance; 
        for (auto n: hashMap[id]->subordinates){
            sum += dfs(employees,n,hashMap); 
        }
        return sum; 
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> hashMap; 
        for (auto e: employees){
            hashMap[e->id] = e; 
        }
        
        
        return dfs(employees,id,hashMap); 
    }
};