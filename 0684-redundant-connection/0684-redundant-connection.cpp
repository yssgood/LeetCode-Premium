class Solution {
public:
    vector<int> parent; 
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]); 
        }
        return parent[x]; 
    }
    bool union_sets(int x, int y){
        int px = find(x), py = find(y); 

        if(px == py) return false; 

        parent[px] = py; 
        return true; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); 
        parent.resize(n+1); 

        for(int i = 1; i <= n; i++){
            parent[i] = i; 
        }

        for(vector<int>& e :edges){
            if(!union_sets(e[0],e[1])){
                return e; 
            }
        }

        return {}; 
    }
};