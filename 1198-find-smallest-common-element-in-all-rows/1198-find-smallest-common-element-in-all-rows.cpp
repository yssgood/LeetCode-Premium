class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> hashMap; 
        int answer = INT_MAX; 
        for(vector<int>& v : mat){
            for(int n : v) hashMap[n]++; 
        }

        for(auto& it : hashMap){
            if(it.second == mat.size()) answer = min(answer, it.first); 
        }

        return answer == INT_MAX ? -1 : answer; 
    }
};