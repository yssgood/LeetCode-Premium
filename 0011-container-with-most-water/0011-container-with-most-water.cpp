class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_ = 0; 
        int p1 = 0, p2 = height.size()-1; 

        while(p1 <= p2){
            int width = p2 - p1; 
            int heights = min(height[p1], height[p2]); 
            max_ = max(max_, width * heights); 
            if(height[p1] <= height[p2]){
                p1++; 
            } else{
                p2--; 
            }
        }

        return max_; 
    }
};