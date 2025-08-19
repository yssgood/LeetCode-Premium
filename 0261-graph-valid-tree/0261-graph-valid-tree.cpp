class Solution {
public:
    unordered_map<int,int> parent; 
    int components; 
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]); 
        }
        return parent[x]; 
    }
    bool union_find(int x, int y){
        int px = find(x), py = find(y); 
        if(px == py){
            return false; 
        }
        parent[px] = py; 
        components--; 
        return true; 
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        components = n; 
        for(int i = 0; i < n; i++){
            parent[i] = i; 
        }
        
        for(vector<int>& edge : edges){
            if(!union_find(edge[0],edge[1])){
                return false; 
            }
        }
        return components == 1; 
    }
};