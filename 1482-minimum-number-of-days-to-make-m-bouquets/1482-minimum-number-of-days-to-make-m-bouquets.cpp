class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size(); 
        if((long long)m * (long long)k > n) return -1; 

        int right = *max_element(bloomDay.begin(), bloomDay.end()); 
        int left = 0; 
        while(left <= right){
            int mid = (right + left) / 2; 

            int tmpM = 0, tmpK = k;  
            for(int i = 0; i < bloomDay.size(); i++){
                int flower = bloomDay[i]; 

                if(flower <= mid){
                    tmpK--; 
                    if(tmpK == 0){
                        tmpM++; 
                        tmpK = k; 
                    }
                } else{
                    tmpK = k; 
                }
            }

            if(tmpM >= m){
                right = mid-1; 
            } else{
                left = mid + 1; 
            }
        }

       
        return left; 
    }
};