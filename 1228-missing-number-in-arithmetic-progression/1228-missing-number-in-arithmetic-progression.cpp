class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int min_value = INT_MAX;
        sort(arr.begin(), arr.end()); 
        for(int i = 1; i < arr.size(); i++){
            min_value = min(min_value, arr[i] - arr[i-1]); 
        }
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] != min_value){
                return arr[i-1] + min_value; 
            }
        }
        return arr[1] - arr[0]; 
    }
};