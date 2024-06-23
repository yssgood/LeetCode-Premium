class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int min_element = INT_MAX; 
        for(int i = 0; i < arr.size()-1; i++){
            min_element = min(min_element, abs(arr[i+1] - arr[i])); 
        }


        for(int i = 0; i < arr.size()-1; i++){
            if(abs(arr[i+1] - arr[i]) > min_element){
                if(arr[i+1] - arr[i] < 0){
                    return arr[i] + min_element * -1; 
                }
                return arr[i] + min_element; 
            }
        }
        return arr[1] - arr[0]; 
    }
};