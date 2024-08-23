class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int curr_max = *max_element(bloomDay.begin(), bloomDay.end()); 
        int right = *max_element(bloomDay.begin(), bloomDay.end()); 
        int left = 0; 

        while(left <= right){
            int mid = (right + left) / 2; 

            int cnt = 0;  
            int res = 0; 
            for(int i = 0; i < bloomDay.size(); i++){
                if(bloomDay[i] <= mid){
                    cnt++; 
                    if(cnt == k){
                        res++; 
                        cnt = 0; 
                    }
                } else{
                    cnt = 0; 
                }
            }

            if(res >= m){
                right = mid - 1; 
            } else{
                left = mid + 1; 
            }
        }

        return left > curr_max ? -1 : left; 
    }
};