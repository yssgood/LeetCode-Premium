class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end()); 
        int left = 1; 

        while(left < right){
            int mid = (left + right) / 2; 
            int hourSpent = 0; 

            for(int pile : piles){
                hourSpent += pile / mid + (pile % mid != 0); 
            }

            if(hourSpent <= h){
                right = mid; 
            } else{
                left = mid + 1;
            }

        }

        return left; 
    }
};