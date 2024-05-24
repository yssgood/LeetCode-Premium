class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curr_min = arrays[0][0], curr_max = arrays[0].back(); 
        int curr_dist = INT_MIN; 
        for(int i= 1; i < arrays.size(); i++){
            int next_min = arrays[i][0], next_max = arrays[i].back(); 
            curr_dist = max(curr_dist, max(abs(curr_min - next_max), abs(curr_max - next_min))); 
            curr_min = min(curr_min,next_min); 
            curr_max = max(curr_max,next_max); 
        }

        return curr_dist; 
    }
};