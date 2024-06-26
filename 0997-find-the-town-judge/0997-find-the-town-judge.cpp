class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty()) return n > 1 ? -1 : 1; 
        
        map<int,int> hashMap; 
        int candidate = 1; 
        for(int i = 0; i < trust.size(); i++){
            //candidate = trust[i][1]; 
            //if(trust[i][0] == candidate) candidate = trust[i][1]; 
            hashMap[trust[i][0]]++; 
        }

        for(int i = 1; i <= n; i++){
            if(hashMap[i] == 0) candidate = i; 
        }

        int count = 0; 
        for(int i = 0; i < trust.size(); i++){
            if(trust[i][0] == candidate) return -1; 
            count += trust[i][1] == candidate ? 1 : 0; 
        }

        cout << candidate; 
        return count == n - 1 ? candidate : -1; 
    }
};