class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size(); 
        int duplicate = -1; 
        while(low <= high){
            int mid = (low + high) / 2; 
            int count = 0; 
            for(int& n : nums){
                if(n <= mid) count++;  
            }

            if(count <= mid){ //정상적인 숫자일 때 
                low = mid + 1;  
            } else{
                duplicate = mid; 
                high = mid - 1; 
            }
        }

        return duplicate; 

    }
};