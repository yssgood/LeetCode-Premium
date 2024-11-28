class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {  
        int max_ = 0;  
        int curr_min = arrays[0][0];
        int curr_max = arrays[0].back(); 
        for(int i = 1; i < arrays.size(); i++){
            int first = abs(curr_max - arrays[i][0]); 
            int second = abs(curr_min - arrays[i].back());
            max_ = max(max_, max(first, second)); 
            curr_min = min(curr_min, arrays[i][0]); 
            curr_max = max(curr_max, arrays[i].back());          
        }

        return max_; 
    }
};