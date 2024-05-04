class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix(gain.size() + 1, 0); 
        for(int i = 1; i <= gain.size(); i++){
            prefix[i] = prefix[i-1] + gain[i-1]; 
        }

        

        return *max_element(prefix.begin(), prefix.end()); 
    }
};