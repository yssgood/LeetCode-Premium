class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> answer(rains.size(),1);
        unordered_map<int,int> fullLakes; 
        set<int> dryDays; 

        for(int i = 0; i < rains.size(); i++){
            if (rains[i] == 0){
                dryDays.insert(i);  
            } else{
                int lake = rains[i]; 
                answer[i] = -1; 

                if(fullLakes.count(lake)){
                    auto it = dryDays.upper_bound(fullLakes[lake]); 
                    if(it == dryDays.end()){
                        return {}; 
                    }
                    answer[*it] = lake; 
                    dryDays.erase(it); 
                }

                fullLakes[lake] = i; 
            }
        }

        return answer; 
    }
};