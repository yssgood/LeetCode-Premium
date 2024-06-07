class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int happy = 0; 
        int answer = 0; 
        map<int,int> hashMap; 
        hashMap[0] = -1; 
        for(int i = 0; i < hours.size(); i++){
            happy += hours[i] > 8 ? 1 : -1; 
            
            if(happy > 0){
                answer = max(answer, i + 1); 
            }

            if(happy <= 0){
                if(hashMap.count(happy - 1)){
                    answer = max(answer, i - hashMap[happy-1]);
                } 
                
                if(!hashMap.count(happy)){
                    hashMap[happy] = i; 
                }
            }
        }
        return answer; 
    }
};