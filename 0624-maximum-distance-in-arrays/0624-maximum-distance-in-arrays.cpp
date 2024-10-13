class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int answer = 0; 
        int curr_min = arrays[0][0]; 
        int curr_max = arrays[0].back();
        for(int i = 1; i < arrays.size(); i++){
            int next_min = arrays[i][0];
            int next_max = arrays[i].back(); 
            answer = max(answer, max(abs(curr_max-next_min), abs(curr_min - next_max)));
            curr_min = min(curr_min, next_min); 
            curr_max = max(curr_max, next_max); 
        }
        return answer; 
    }
};