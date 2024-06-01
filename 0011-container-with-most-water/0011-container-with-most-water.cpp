class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1; 
        int curr_max = 0; 

        while(left < right){
            int width = right - left; 
            curr_max = max(curr_max, min(height[right],height[left]) * width); 

            if(height[left] < height[right]){
                left++; 
            } else{
                right--; 
            }
        }

        return curr_max; 
    }
};