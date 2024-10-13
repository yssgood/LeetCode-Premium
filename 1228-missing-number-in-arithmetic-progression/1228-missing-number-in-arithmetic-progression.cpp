class Solution {
public:
    int missingNumber(vector<int>& arr) {
        //first and last elements are not removed 
        //[5, 7, 9, 11, 15] 
        //[15,13,12]

        int n = arr.size(); 
        int diff = (arr.back() - arr.front()) / n; 

        int left = 0, right = arr.size()-1; 
        int front = arr[0]; 

        while(left < right){
            int mid = (right + left) / 2; 
            if(arr[mid] == front + (mid * diff)){
                left = mid + 1; 
            } else{
                right = mid; 
            }
        }

        return front + left * diff; 
    }
};