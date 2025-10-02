class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1; 
        int max_ = 0; 
        while(start < end){
            int x = end - start; 
            int y = min(height[start],height[end]); 
            max_ = max(max_, x * y); 
            if(height[start] < height[end]){
                start++; 
            } else if(height[start] > height[end]){
                end--; 
            } else{
                start++;
                end--; 
            }
        }
        return max_; 
    }
};