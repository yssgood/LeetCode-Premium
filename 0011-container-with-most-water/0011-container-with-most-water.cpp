class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1; 
        int curr_min = INT_MAX, max_area = INT_MIN; 
        while(left < right){
            int width = (right - left); 
            curr_min = min(height[left], height[right]); 
            max_area = max(max_area, width * curr_min); 
            if(height[left] > height[right]){
                right--; 
            } else if(height[right] > height[left]){
                left++; 
            } else{
                left++;
                right--; 
            }
        }

        return max_area; 
    }
};