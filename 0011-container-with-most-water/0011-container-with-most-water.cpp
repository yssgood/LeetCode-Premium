class Solution {
public:
    int maxArea(vector<int>& height) {
        int areaMax = 0; 
        int left = 0; 
        int right = height.size() - 1; 
        int width; 
        int compare; 
        int minimum;
        while (left < right){
            width = right - left; 
            minimum = min(height[left],height[right]);
            compare = width * minimum;
            areaMax = max(areaMax, compare); 
            
            height[left] < height[right] ? left++ : right--; 
        }
        
        return areaMax; 
    }
};