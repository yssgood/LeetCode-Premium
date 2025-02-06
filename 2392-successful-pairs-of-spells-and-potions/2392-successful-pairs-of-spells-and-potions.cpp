class Solution {
public:
    int findLowerBound(vector<int>& potions, int currSpell, long long success){
        int left = 0, right = potions.size()-1; 
        while(left <= right){
            int mid = (right + left) / 2; 
            long long midVal = (long long)potions[mid] * currSpell; 

            if(midVal >= success){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }
        return left; 
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); 
        vector<int> answer(spells.size(),0); 
        for(int i = 0; i < spells.size(); i++){
            int index = findLowerBound(potions,spells[i],success); 
            //cout << index << endl; 
            answer[i] = potions.size() - index; 
        }
        return answer; 
    }
};