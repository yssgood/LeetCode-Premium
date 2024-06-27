class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> hashMap; 
        for(vector<int>& v : edges){
            int from = v[0], to = v[1]; 
            hashMap[from]++;
            hashMap[to]++; 
        }
        for(auto& it : hashMap){
            if(hashMap[it.first] == hashMap.size()-1){
                return it.first; 
            }
        }

        return 1; 
    }
};