class Solution {
public:
    int binarySearch(int spell, vector<int>& potions, long long success){
        int left = 0, right = potions.size()-1; 

        while(left <= right){
            int mid = (right + left) / 2; 
            long long curr = (long long)potions[mid] * (long long)spell; 

            if(curr >= success){
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
        int n = potions.size(); 
        for(int i = 0; i < spells.size(); i++){
            int lowerBound = binarySearch(spells[i],potions,success); 
            answer[i] = n - lowerBound; 
        }
        return answer; 
    }
};