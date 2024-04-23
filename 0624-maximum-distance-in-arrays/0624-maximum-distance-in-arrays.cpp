class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curr_min = arrays[0][0], curr_max = arrays[0].back(); 
        int max_dist = INT_MIN; 
        for(int i = 1; i < arrays.size(); i++){
            int next_min = arrays[i][0], next_max = arrays[i].back(); 
            max_dist = max(max_dist, max(abs(curr_max - next_min), abs(curr_min - next_max))); 
            curr_min = min(curr_min, next_min);
            curr_max = max(curr_max, next_max); 
        }
        
        return max_dist; 
    }
};