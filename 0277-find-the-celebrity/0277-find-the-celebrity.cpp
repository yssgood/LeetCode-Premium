/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<pair<int,int>> knowMap(n); 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue; 

                if(knows(i,j)){
                    knowMap[i].first++; 
                    knowMap[j].second++; 
                }
            }
        }

        for(int i = 0; i < knowMap.size(); i++){
            if(knowMap[i].first == 0 && knowMap[i].second == n - 1) return i; 
        }
        return -1; 
    }
};