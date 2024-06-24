class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> answer(spells.size(),0); 
        sort(potions.begin(), potions.end()); 
        int pSize = potions.size(); 
        for(int i = 0; i < spells.size(); i++){
            if((long long)spells[i] * (long long)potions.back() < success) continue; 
            int left = 0, right = potions.size()-1; 

            while(left < right){
                int mid = (right + left) / 2; 

                long long curr = (long long)spells[i] * (long long)potions[mid]; 

                if(curr >= success){
                    right = mid; 
                } else{
                    left = mid + 1; 
                }
            }

            answer[i] = pSize - left; 

        }
        return answer; 
    }
};