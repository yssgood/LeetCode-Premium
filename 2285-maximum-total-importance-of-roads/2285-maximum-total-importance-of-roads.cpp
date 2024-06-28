class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> hashMap; 
        for(vector<int>& v : roads){
            int from = v[0], to = v[1]; 
            hashMap[from]++; 
            hashMap[to]++; 
        }

        vector<int> nodes; 
        for(int i = 0; i < n; i++) nodes.push_back(i); 
        sort(nodes.begin(), nodes.end(),[&](int& a, int& b){
            return hashMap[a] > hashMap[b]; 
        });

        for(int next : nodes){
            hashMap[next] = n--;  
        }

        long long answer = 0; 
        for(vector<int>& v : roads){
            int from = v[0], to = v[1]; 
            answer += hashMap[from];
            answer += hashMap[to]; 
        }

        return answer; 
    }
};