class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) return false; 
        for(int i = 1; i < arr.size()-1; i++){
            if(arr[i] % 2 == 1 && arr[i-1] % 2 == 1 && arr[i+1] % 2 == 1) return true; 
        }
        return false; 
    }
};