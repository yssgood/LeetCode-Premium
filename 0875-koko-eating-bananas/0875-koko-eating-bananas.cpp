class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long min_k = 1;
        long long max_k = *max_element(piles.begin(),piles.end()); 
        long long answer = INT_MAX; 
        while(min_k <= max_k){
            long long mid = (max_k + min_k) / 2;  

            long time = 0; 
            for(int n : piles){
                time += (n / mid); 
                time += (n % mid > 0) ? 1 : 0; 
            }

            if(time <= h){
                answer = min(answer,mid); 
                max_k = mid - 1; 
            } else{
                min_k = mid + 1; 
            }
        }

        return answer; 
    }
};