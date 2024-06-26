class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty()) return n == 1 ? 1 : -1; 

        vector<pair<int,int>> check(n+1); 
        for(vector<int>& v : trust){
            int from = v[0], to = v[1]; 
            check[from].second++; 
            check[to].first++; //first represents person who trust me, second represents person I trust to  
        }

        for(int i = 1; i <= n; i++){
            if(check[i].first == n-1 && check[i].second == 0){
                return i; 
            }
        }

        return -1; 
    }
};