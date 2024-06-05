class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1; 
        int curr_max = 0;  
        while(start < end){
            int width = end - start; 
            curr_max = max(curr_max, min(height[start], height[end]) * width); 
            if(height[start] < height[end]){
                start++; 
            } else{
                end--; 
            }
        }
        return curr_max; 
    }
};