class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());  
        int left = 1; 

        while(left < right){
            int mid = (right + left) / 2; 
            
            int tmpH = 0; 
            for(int i = 0; i < piles.size(); i++){
                tmpH += piles[i] / mid + (piles[i] % mid != 0); 
            }

            if(tmpH <= h){
                right = mid; 
            } else{
                left = mid + 1; 
            }
        }

        return left; 
    }
};