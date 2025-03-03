class Solution {
public:
    int minSwaps(vector<int>& data) {
        int win_size = 0; 
        for(int n : data) win_size += (n == 1) ? 1 : 0; 
        int left = 0, right = 0; 
        int countOnes = 0, max_ = 0; 
        while(right < data.size()){
            countOnes += (data[right] == 1) ? 1 : 0; 
            if(right - left + 1> win_size){
                countOnes -= (data[left] == 1) ? 1 : 0; 
                left++; 
            }
            max_ = max(max_, countOnes); 
            right++; 
        }
        return win_size - max_; 
    }
};